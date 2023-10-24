#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int MAXLG = 31 - __builtin_clz(MAXN) + 1;

int N;
int value[MAXN];
int table[MAXN][MAXLG];

void calc(){
	for(int i=0; i<N; i++) table[i][0] = value[i];

	for(int p=1; p < MAXLG; p++)
		for(int i=0; i + (1 << p) <= N; i++)
			table[i][p] = min(table[i][p-1], table[i+(1 << (p-1))][p-1]);
}

int query(int l, int r){
	int p = 31 - __builtin_clz(r - l + 1);	//floor log
	return min(table[l][p], table[ r - (1<<p) + 1 ][p]);
}


int main(){
	cout << "Sparse Table - Minimum Query" << endl;
	return 0;	
}


/******************************************************
Sparse Table for Range Minimum Query [L, R]

Calc:  	O(N log N)
Query:	O(1)

0-indexado!
Value -> Array Original
*******************************************************/