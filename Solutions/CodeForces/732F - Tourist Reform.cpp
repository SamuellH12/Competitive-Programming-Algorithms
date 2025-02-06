#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;

// https://codeforces.com/problemset/problem/732/F

int pai[MAXN], sz[MAXN];

inline void resetDSU(){ for(int i=0; i<MAXN; i++) sz[i] = 1, pai[i] = i; }
inline int find(int u){  return ( pai[u] == u  ?  u  :  pai[u] = find(pai[u]) );  }

inline void join(int u, int v){
	u = find(u);
	v = find(v);

	if(u == v) return;
	if(sz[v] > sz[u]) swap(u, v);

	pai[v] = u;
	sz[u] += sz[v];
}


int pre[MAXN], low[MAXN], clk=0;
pii arestas[MAXN];
bool dir   [MAXN];

vector<pii> grafo[MAXN];
vi pontes;

void tarjan(int u, int p = -1){
	pre[u] = low[u] = clk++;

	for(auto [v, id] : grafo[u])
	{
		if(v == p) continue;

		if(pre[v] == -1){
			tarjan(v, u);

			low[u] = min(low[v], low[u]);

			if(low[v] >  pre[u]) pontes.emplace_back(id);
			else join(u, v);

			dir[id] = ( u == arestas[id].first ? 1 : 0 );
		}
		else low[u] = min(low[u], pre[v]), dir[id] = ( u == arestas[id].first ? 0 : 1 );;
		
	}

}


vector<pii> trafo[MAXN];

void dfs(int u, int p){
	for(auto [v, id] : trafo[u]){
		if(v == p) continue;

		dir[id] = (find(u) == find(arestas[id].first) ? 0 : 1);
		dfs(v, u);
	}
}


int main(){
	optimize;
	memset(pre, -1, sizeof pre);

	int n, m;
	cin >> n >> m;

	for(int i=0, u, v; i<m; i++){
		cin >> u >> v;

		grafo[u].emplace_back(v, i);
		grafo[v].emplace_back(u, i);

		arestas[i] = pii(u, v);
	}


	resetDSU();
	tarjan(1);


	int ans = 0, st=-1;

	for(int i=1, u; i<=n; i++)
	{
		u = find(i);
		if(sz[u] > ans) ans = sz[u], st=u;
	}

	for(auto id : pontes)
	{
		auto [u, v] = arestas[id];
		u = find(u);
		v = find(v);

		trafo[u].emplace_back(v, id);
		trafo[v].emplace_back(u, id);
	}


	if(st != -1) dfs(st, -1);
	else ans = n;



	cout << ans << endl;

	for(int i=0; i<m; i++)
	{
		if(dir[i]) cout << arestas[i].first << " " << arestas[i].second << endl;
		else cout << arestas[i].second << " " << arestas[i].first << endl;
	}
	
	
	return 0;	
}
