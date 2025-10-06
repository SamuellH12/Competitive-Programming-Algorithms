#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define endl "\n"
using namespace std;

struct DSU {
	vector<int> pai, sz;
	DSU(int n) : pai(n+1), sz(n+1, 1) {
		for(int i=0; i<=n; i++) pai[i] = i;
	}
	
	int find(int u){ return pai[u] == u ? u : pai[u] = find(pai[u]); }

	void join(int u, int v){
		u = find(u), v = find(v);

		if(u == v) return;
		if(sz[v] > sz[u]) swap(u, v);

		pai[v] = u;
		sz[u] += sz[v];
	}
};

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;

	vector<pii> edges(m);
	for(auto &[u, v] : edges) cin >> u >> v, u--, v--;
	
	vector<pii> queries(q);
	for(auto &[u, v] : queries) cin >> u >> v, u--, v--;

	DSU dsu(0);
	auto reset = [&](){ dsu = DSU(n); };
	auto update = [&](int mid){ if(mid) dsu.join(edges[mid-1].first, edges[mid-1].second); };
	auto check = [&](int i){ return dsu.find(queries[i].first) == dsu.find(queries[i].second); };

	int k = m+1;
	bool LACK = true; 
    vector<int> L(q, 0), R(q, k-1), ans(q, -1);
    vector<vector<int>> atMid(k);
    
    while(LACK){
        reset(); LACK = false;

        for(int i=0; i<q; i++)
            if(L[i] <= R[i])
                atMid[(L[i]+R[i])/2].push_back(i), LACK = true;
        
        for(int mid=0; mid<k; mid++){
            update(mid);
            for(auto i : atMid[mid])
                if(check(i)) R[i] = mid-1, ans[i] = mid;
                else L[i] = mid+1;
            atMid[mid].clear();
        }
    }

	for(auto &x : ans) cout << x << endl;
}