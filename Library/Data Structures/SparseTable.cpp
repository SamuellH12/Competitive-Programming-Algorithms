#include <bits/stdc++.h>
using namespace std;

template<typename T> struct Sparse {
	vector<vector<T>> table;

	void build(vector<T> &v){
		int N = v.size(), MLOG = 32 - __builtin_clz(N);
		table.assign(MLOG, v);

		for(int p=1; p < MLOG; p++)
			for(int i=0; i + (1 << p) <= N; i++)
				table[p][i] = min(table[p-1][i], table[p-1][i+(1<<(p-1))]);
	}

	T query(int l, int r){
		int p = 31 - __builtin_clz(r - l + 1);	//floor log
		return min(table[p][l], table[p][ r - (1<<p)+1 ]);
	}
};

/*************************************************
Sparse Table for Range Minimum Query [L, R] [0, N-1]
build:  O(N log N)	
Query:  O(1)
build(v) -> v = Original Array
if you want a static array, do this: for(int i=0; i<N; i++) table[0][i] = v[i];
*************************************************/