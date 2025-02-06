#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

template<typename T> struct SegTree {
	int n;
	vector<T> seg;
	T join(T&l, T&r){ return max(l, r); }

	void init(vector<T>&base){
		n = base.size();
		seg.resize(2*n);
		for(int i=0; i<n; i++) seg[i+n] = base[i];
		for(int i=n-1; i; i--) seg[i] = join(seg[i*2], seg[i*2+1]);
	}

	T query(int l, int r){ //[L, R]
		T ans = 0; //NEUTRO
		for(l+=n, r+=n+1; l<r; l/=2, r/=2){
			if(l&1) ans = join(ans, seg[l++]);
			if(r&1) ans = join(seg[--r], ans);
		}
		return ans;
	}

	void update(int i, T v){
		for(seg[i+=n] = v; i/=2;) seg[i] = join(seg[i*2], seg[i*2+1]);
	}
}; 
SegTree<int> seg;

const bool EDGE = false;
struct HLD {
public:
	vector<vector<int>> g; //grafo
	vector<int> sz, parent, tin, nxt;
	int n;
	HLD(){}
	HLD(int n){ init(n); }
	void init(int _n){
		t = 0; n = _n;
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

	int query_path(int u, int v){
		if(tin[u] < tin[v]) swap(u, v);
		if(nxt[u] == nxt[v]) return qry(tin[v]+EDGE, tin[u]);
		return max(qry(tin[nxt[u]], tin[u]), query_path(parent[nxt[u]], v));
	}

	void update_path(int u, int v, int x){
		if(tin[u] < tin[v]) swap(u, v);
		if(nxt[u] == nxt[v]) return updt(tin[v]+EDGE, tin[u], x);
		updt(tin[nxt[u]], tin[u], x); update_path(parent[nxt[u]], v, x);
	}
private:
	int qry(int l, int r){ return seg.query(l, r);    }	
	void updt(int l, int r, int x){ seg.update(l, x); }

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
};

int main(){ 
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;

	vector<int> val(n);
	for(auto &x : val) cin >> x;

	HLD hld(n);

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		u--, v--;
		hld.addEdge(u, v);
	}

	hld.build();
	vector<int> val2(n);
	for(int i=0; i<n; i++) 
		val2[hld.tin[i]] = val[i];
	seg.init(val2);

	int op, a, b;
	while(q--)
	{
		cin >> op >> a >> b;

		if(op&1) hld.update_path(a-1, a-1, b);
		else cout << hld.query_path(a-1, b-1) << " ";
	}
	cout << "\n";

	return 0; 
}
