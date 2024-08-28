#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int pai[MAXN], sz[MAXN];

int find(int u){ 
	return ( pai[u] == u  ?  u  :  pai[u] = find(pai[u]) ); 
}

void join(int u, int v){
	u = find(u);
	v = find(v);

	if(u == v) return;
	if(sz[v] > sz[u]) swap(u, v);

	pai[v] = u;
	sz[u] += sz[v];
}

void resetDSU(){
	for(int i=0; i<MAXN; i++) 
		sz[i] = 1, pai[i] = i;
}
/*************************************************
	Disjoint Set Union - Union Find
-> Complexity:
 - Find: O( α(n) ) -> Inverse Ackermann function 
 - Join: O( α(n) ) -> Inverse Ackermann function 
α(n) <= 4 Para todos os casos práticos
*************************************************/