#include <bits/stdc++.h>
using namespace std;

struct DSUr {
	vector<int> pai, sz, savept;
	stack<pair<int&, int>>  st;
	DSUr(int n) : pai(n+1), sz(n+1, 1) {
		for(int i=0; i<=n; i++) pai[i] = i;
	}
	
	int find(int u){ return pai[u] == u ? u : find(pai[u]); }

	void join(int u, int v){
		u = find(u), v = find(v);
		
		if(u == v) return;
		if(sz[v] > sz[u]) swap(u, v);

		save(pai[v]); pai[v] = u;
		save(sz[u]);  sz[u] += sz[v];
	}
	
	void save(int &x){ st.emplace(x, x); }
	void pop(){
		st.top().first = st.top().second; st.pop();
		st.top().first = st.top().second; st.pop();
	}

	void checkpoint(){ savept.push_back(st.size()); }
	void rollback(){
		while(st.size() > savept.back()) pop();
		savept.pop_back();
	}
};
/*************************************************
Disjoint Set Union with Rollback - O(Log n)
checkpoint() -> salva o estado atual
rollback() -> restaura no último checkpoint
save another var? +save in join & +line in pop 
*************************************************/