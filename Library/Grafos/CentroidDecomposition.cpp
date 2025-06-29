#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;

vector<int> grafo[MAXN];
deque<int> distToAncestor[MAXN];

bool rem[MAXN];
int szt[MAXN], parent[MAXN];

void getDist(int u, int p, int d=0){
	for(auto v : grafo[u])
		if(v != p && !rem[v])
			getDist(v, u, d+1);
	distToAncestor[u].emplace_front(d);
}

int getSz(int u, int p){
	szt[u] = 1;
	for(auto v : grafo[u])
		if(v != p && !rem[v])
			szt[u] += getSz(v, u);
	return szt[u];
}

void dfsc(int u=0, int p=-1, int f=-1, int sz=-1){
	if(sz < 0) sz = getSz(u, -1); //starting new tree
	
	for(auto v : grafo[u])
		if(v != p && !rem[v] && szt[v]*2 >= sz)
			return dfsc(v, u, f, sz);

	rem[u] = true, parent[u] = f;
	getDist(u, -1, 0); //get subtree dists to centroid
	
	for(auto v : grafo[u])
		if(!rem[v]) 
			dfsc(v, u, u, -1);
}

/*LATEX_DESC_BEGIN***************************
Centroid Decomposition 	 	 	 	 	 	

**Complexity:** O(N*LogN)

dfsc() -> para criar a centroid tree

rem[u]    -> True se U já foi removido (pra dfsc)
szt[u]    -> Size da subárvore de U (pra dfsc)
parent[u] -> Pai de U na centroid tree *parent[ROOT] = -1
distToAncestor[u][i] -> Distância na árvore original de u para
seu i-ésimo pai na centroid tree *distToAncestor[u][0] = 0

dfsc(u=node, p=parent(subtree), f=parent(centroid tree), sz=size of tree)
*****************************LATEX_DESC_END*/