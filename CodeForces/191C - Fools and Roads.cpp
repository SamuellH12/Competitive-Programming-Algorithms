#include <bits/stdc++.h>
#define ll long long
using namespace std;
//https://codeforces.com/problemset/problem/191/C

const int MAXN = 1e5 + 10;
int bit [MAXN];

int queryb(int pos){
	int sum = 0;
	for(; pos>0; pos -= pos&-pos)
		sum += bit[pos];
	return sum;
}
void updateb(int pos, int v){
	for(; pos<MAXN; pos+=pos&-pos)
		bit[pos] += v;
}

const bool EDGE = true;
struct HLD {
public:
	vector<vector<int>> g; //grafo
	vector<int> sz, parent, tin, nxt;
	HLD(){}
	HLD(int n){ init(n); }
	void init(int n){
		t = 0;
		g.resize(n); tin.resize(n);
		sz.resize(n);nxt.resize(n);
		parent.resize(n);
	}
	void addEdge(int u, int v){
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	void build(int root=0){
		nxt[root]=root;
		dfs(root, root);
		hld(root, root);
	}

	ll query_path(int u, int v){
		if(tin[u] < tin[v]) swap(u, v);
		if(nxt[u] == nxt[v]) return qry(tin[v]+EDGE, tin[u]);
		return qry(tin[nxt[u]], tin[u]) + query_path(parent[nxt[u]], v);
	}

	void update_path(int u, int v, ll x){
		if(tin[u] < tin[v]) swap(u, v);
		if(nxt[u] == nxt[v]) return updt(tin[v]+EDGE, tin[u], x);
		updt(tin[nxt[u]], tin[u], x); update_path(parent[nxt[u]], v, x);
	}

	ll query_pathi(int u, int v){
		ll ans = 0; //NEUTRO
		while(!inSubtree(nxt[u], v)) ans += qry(tin[nxt[u]], tin[u]), u = parent[nxt[u]];
		while(!inSubtree(nxt[v], u)) ans += qry(tin[nxt[v]], tin[v]), v = parent[nxt[v]];
		return ans + qry(min(tin[u], tin[v])+EDGE, max(tin[u], tin[v]));
	}
	void update_pathi(int u, int v, ll x){
		while(!inSubtree(nxt[u], v)) updt(tin[nxt[u]], tin[u], x), u = parent[nxt[u]];
		while(!inSubtree(nxt[v], u)) updt(tin[nxt[v]], tin[v], x), v = parent[nxt[v]];
		updt(min(tin[u], tin[v])+EDGE, max(tin[u], tin[v]), x);
	}

private:
	ll qry(int l, int r){ 
		if(l>r) return 0;/*NEUTRO*/ 
		return queryb(r);
	}
	void updt(int l, int r, ll x){ 
		if(l>r) return; 
		updateb(l, x);
		updateb(r+1, -x);
	}

	void dfs(int u, int p){
		sz[u] = 1, parent[u] = p;
		for(auto &v : g[u]) if(v != p) {
			dfs(v, u); sz[u] += sz[v];
		
			if(sz[v] > sz[g[u][0]] || g[u][0] == p) 
				swap(v, g[u][0]);
		}
	}

	int t=0;
	void hld(int u, int p){
		tin[u] = t++;
		for(auto &v : g[u]) if(v != p)
			nxt[v] = (v == g[u][0] ? nxt[u] : v),
			hld(v, u);
	}

	//////// OPTIONAL: ////////

	int lca(int u, int v){
		while(!inSubtree(nxt[u], v)) u = parent[nxt[u]];
		while(!inSubtree(nxt[v], u)) v = parent[nxt[v]];
		return tin[u] < tin[v] ? u : v;
	}

	bool inSubtree(int u, int v){ return tin[u] <= tin[v] && tin[v] < tin[u] + sz[u]; } 
	//query/update_subtree[tin[u]+EDGE, tin[u]+sz[u]-1];
	///////////////////////////
};

int main(){ 
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n; 

	HLD hld(n);

	vector<pair<int, int>> arestas;
	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		u--, v--;
		hld.addEdge(u, v);
		arestas.emplace_back(u, v);
	}

	hld.build();

	int k, u, v; cin >> k;
	while(k--)
	{
		cin >> u >> v;
		u--, v--;
		hld.update_pathi(u, v, 1);
	}

	for(auto [u, v] : arestas)
		cout << hld.query_pathi(u, v) << " ";
	cout << endl;

	return 0; 
}