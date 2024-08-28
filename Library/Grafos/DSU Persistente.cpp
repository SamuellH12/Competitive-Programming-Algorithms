#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int pai[MAXN], sz[MAXN], tim[MAXN], t=1;

int find(int u, int q = INT_MAX){ 
	if( pai[u] == u || q < tim[u] ) return u;
	return find(pai[u], q); 
}

void join(int u, int v){
	u = find(u);
	v = find(v);

	if(u == v) return;
	if(sz[v] > sz[u]) swap(u, v);

	pai[v] = u;
	tim[v] = t++;
	sz[u] += sz[v];
}

void resetDSU(){
	for(int i=0; i<MAXN; i++) sz[i] = 1, pai[i] = i;
	memset(tim, 0, sizeof tim);
}
/*************************************************
	SemiPersistent Disjoint Set Union

-> Complexity: O( Log N )
find(u, q) -> Retorna o representante do conjunto de U no tempo Q

 * Não é possível utilizar Path Compression
 * tim -> tempo em que o pai de U foi alterado
*************************************************/