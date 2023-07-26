#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int pai[MAXN], sz[MAXN], tim[MAXN], t=1;

inline int find(int u, int q = INT_MAX){ 
	if( pai[u] == u || pai[u] == -1 || q < tim[u] ) return u;
	return find(pai[u], q); 
}

inline void join(int u, int v){
	u = find(u);
	v = find(v);

	if(u == v) return;
	if(sz[v] > sz[u]) swap(u, v);

	pai[v] = u;
	tim[v] = t++;
	sz[u] += sz[v];
}

inline void resetDSU(){
	memset(pai, -1, sizeof pai);
	for(int i=0; i<MAXN; i++) sz[i] = 1;
	memset(tim, 0, sizeof tim);
}



int main(){
	resetDSU();
	cout << "Persistent Disjoint Set Union - Persistent Union Find" << endl;
	return 0;	
}

/*************************************************
-> Complexity:

 - Find: O( Log N )

  find(u, q) -> Retorna o representante do conjunto de U no tempo Q

 * Não é possível utilizar Path Compression
 * tim -> tempo em que o pai de U foi alterado
*************************************************/