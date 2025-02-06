#include <bits/stdc++.h>
using namespace std;

struct BIT {
	vector<int> bit;
	int N;

	BIT(){}
	BIT(int n) : N(n+1), bit(n+1){}

	void update(int pos, int val){
		for(; pos < N; pos += pos&(-pos))
			bit[pos] += val;
	}

	int query(int pos){
		int sum = 0;
		for(; pos > 0; pos -= pos&(-pos))
			sum += bit[pos];
		return sum;
	}
};