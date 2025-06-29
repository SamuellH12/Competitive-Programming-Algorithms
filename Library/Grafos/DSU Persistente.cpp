#include <bits/stdc++.h>
using namespace std;

struct DSUp {
	vector<int> pai, sz, tim;
	int t=1;
	DSUp(int n) : pai(n+1), sz(n+1, 1), tim(n+1) {
		for(int i=0; i<=n; i++) pai[i] = i;
	}
	
	int find(int u, int q = INT_MAX){ 
		if( pai[u] == u || q < tim[u] ) return u;
		return find(pai[u], q); 
	}

	void join(int u, int v){
		u = find(u), v = find(v);
		
		if(u == v) return;
		if(sz[v] > sz[u]) swap(u, v);

		pai[v] = u;
		tim[v] = t++;
		sz[u] += sz[v];
	}
};
/*LATEX_DESC_BEGIN***************************
SemiPersistent Disjoint Set Union - O(Log n)
find(u, q) -> Retorna o pai de U no tempo q
* tim -> tempo em que o pai de U foi alterado
*****************************LATEX_DESC_END*/