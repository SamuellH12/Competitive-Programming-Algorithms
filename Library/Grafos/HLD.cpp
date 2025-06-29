#include <bits/stdc++.h>
#define ll long long
using namespace std;

const bool EDGE = false;
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

private:
	ll qry(int l, int r){ if(EDGE && l>r) return 0;/*NEUTRO*/ } //call Seg, BIT, etc
	void updt(int l, int r, ll x){ if(EDGE && l>r) return; }    //call Seg, BIT, etc

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

	/// OPTIONAL ///
	int lca(int u, int v){
		while(!inSubtree(nxt[u], v)) u = parent[nxt[u]];
		while(!inSubtree(nxt[v], u)) v = parent[nxt[v]];
		return tin[u] < tin[v] ? u : v;
	}
	bool inSubtree(int u, int v){ return tin[u] <= tin[v] && tin[v] < tin[u] + sz[u]; } 
	//query/update_subtree[tin[u]+EDGE, tin[u]+sz[u]-1];
};

/*LATEX_DESC_BEGIN***************************
Heavy-Light Decomposition

**Complexity:** O(LogN * (qry || updt)) 

Change qry(l, r) and updt(l, r) to call a query and update structure of your will

HLD hld(n); //call init
hld.add_edges(u, v); //add all edges
hld.build(); //Build everthing for HLD

tin[u] -> Pos in the structure (Seg, Bit, ...)
nxt[u] -> Head/Endpoint
IMPORTANTE! o grafo deve estar 0-indexado!
*****************************LATEX_DESC_END*/