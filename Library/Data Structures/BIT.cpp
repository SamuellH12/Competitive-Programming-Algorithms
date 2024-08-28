#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

struct BIT {
	int bit[MAXN];

	void update(int pos, int val){
		for(; pos < MAXN; pos += pos&(-pos))
			bit[pos] += val;
	}

	int query(int pos){
		int sum = 0;
		for(; pos > 0; pos -= pos&(-pos))
			sum += bit[pos];
		return sum;
	}
};

/******************************************************
Syntax:
Bit.update(i, x);	//Adiciona +x na posição i da BIT
Bit.query(i)  		//Retorna o somatório de [1, i]
Query: 	O(log n)
Update:	O(log n)
******************************************************/