#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXLG = 31 - __builtin_clz(MAXN) + 1;

int value[MAXN], table[MAXLG][MAXN];

void build(int N){
	for(int i=0; i<N; i++) table[0][i] = value[i];

	for(int p=1; p < MAXLG; p++)
		for(int i=0; i + (1 << p) <= N; i++)
			table[p][i] = min(table[p-1][i], table[p-1][i+(1 << (p-1))]);
}

int query(int l, int r){
	int p = 31 - __builtin_clz(r - l + 1);	//floor log
	return min(table[p][l], table[p][ r - (1<<p) + 1 ]);
}
/*************************************************
Sparse Table for Range Minimum Query [L, R] [0, N)
build:  O(N log N)
Query:  O(1)
Value -> Original Array
*************************************************/