#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define endl '\n'
const int MAXN = 1e5 + 5;
//https://codeforces.com/contest/342/problem/E

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

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q;
	cin >> n >> q;

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		u--, v--;
		grafo[u].emplace_back(v);
		grafo[v].emplace_back(u);
	}

	dfsc();

	vector<int> closer(n, INF);
	auto paint = [&](int u){
		int p = u, i=0;
		while(~p){
			closer[p] = min(closer[p], distToAncestor[u][i]);
			p = parent[p]; i++;
		}
	};
	auto getCloser = [&](int u){
		int p = u, i=0, ans = closer[u];
		while(~p){
			ans = min(ans, closer[p] + distToAncestor[u][i]);
			p = parent[p]; i++;
		}
		return ans;
	};

	paint(0);

	int t, v;
	while(q--)
	{
		cin >> t >> v; v--;
		
		if(t&1) paint(v);
		else cout << getCloser(v) << endl;
	}
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