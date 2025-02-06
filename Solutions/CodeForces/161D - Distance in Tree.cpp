#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50000;
//https://codeforces.com/contest/161/problem/D

vector<int> grafo[MAXN];
deque<int> distToAncestor[MAXN];

bool rem[MAXN];
int szt[MAXN], parent[MAXN];
int k;
long long ans = 0;

void getDist(int u, int p, int d, vector<int> &dists){
	for(auto v : grafo[u])
		if(v != p && !rem[v])
			getDist(v, u, d+1, dists);
	distToAncestor[u].emplace_front(d);
	dists.emplace_back(d);
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
	vector<int> cnt(sz, 0);
	cnt[0] = 1;

	for(auto v : grafo[u])
		if(!rem[v]) 
		{
			vector<int> dists;
			getDist(v, u, 1, dists);

			for(auto d : dists)
				if(d <= k && k-d < sz)
					ans += cnt[k-d];

			for(auto d : dists) cnt[d]++;
		}
	
	for(auto v : grafo[u])
		if(!rem[v]) 
			dfsc(v, u, u, -1);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n >> k;

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		u--, v--;
		grafo[u].emplace_back(v);
		grafo[v].emplace_back(u);
	}

	dfsc();

	cout << ans << endl;

	return 0;
}

/****************************
Centroid Decomposition

dfsc() -> para criar a centroid tree

rem[u]    -> True se U já foi removido
szt[u]    -> Size da subárvore de U
parent[u] -> Pai de U na centroid tree *parent[ROOT] = -1
distToAncestor[u][i] -> Distância na árvore original de u para
	seu i-ésimo pai na centroid tree *distToAncestor[u][0] = 0

dfsc(u=node, p=pai na subtree, f=pai na centroid tree, sz=size of tree)
*****************************/