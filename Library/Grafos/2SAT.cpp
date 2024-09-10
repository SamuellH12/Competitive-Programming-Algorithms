#include <bits/stdc++.h>
using namespace std;

struct TwoSat {
	int N;
	vector<vector<int>> E;
	
	TwoSat(int N) : N(N), E(2 * N) {}
	inline int eval(int u) const{ return u < 0 ? ((~u)+N)%(2*N) : u; }

	void add_or(int u, int v){
		E[eval(~u)].push_back(eval(v));
		E[eval(~v)].push_back(eval(u));
  	}
	void add_nand(int u, int v) {
		E[eval(u)].push_back(eval(~v));
		E[eval(v)].push_back(eval(~u));
	}
	void set_true (int u){ E[eval(~u)].push_back(eval(u)); }
	void set_false(int u){ set_true(~u); }
	void add_imply(int u, int v){ E[eval(u)].push_back(eval(v)); }
	void add_and  (int u, int v){ set_true(u);  set_true(v);    }
	void add_nor  (int u, int v){ add_and(~u, ~v); }
	void add_xor  (int u, int v){ add_or(u, v); add_nand(u, v); }
	void add_xnor (int u, int v){ add_xor(u, ~v); }

	vector<bool> solve() {
		vector<bool> ans(N);
		auto scc = tarjan();

		for (int u = 0; u < N; u++)
			if(scc[u] == scc[u+N]) return {}; //false
			else ans[u] = scc[u+N] > scc[u];

		return ans;	//true
	}
private:
	vector<int> tarjan() {
		vector<int> low(2*N), pre(2*N, -1), scc(2*N, -1);
		stack<int> st;
		int clk = 0, ncomps = 0;

		auto dfs = [&](auto&& dfs, int u) -> void {
			pre[u] = low[u] = clk++;
			st.push(u);
			
			for(auto v : E[u])
				if(pre[v] == -1) dfs(dfs, v), low[u] = min(low[u], low[v]);
				else 
				if(scc[v] == -1) low[u] = min(low[u], pre[v]);

			if(low[u] == pre[u]){ 
				int v = -1;
				while(v != u) scc[v = st.top()] = ncomps, st.pop();
				ncomps++;
			} 
		};

		for(int u=0; u < 2*N; u++)
			if(pre[u] == -1)
				dfs(dfs, u);
	
		return scc; //tarjan SCCs order is the reverse of topoSort, so (u->v if scc[v] <= scc[u])
	}
};

/************************************
  2 SAT - Two Satisfiability Problem

IMPORTANTE! o grafo deve estar 0-indexado!

inverso de u = ~u

Retorna uma valoração verdadeira se possível
Ou um vetor vazio se impossível;
************************************/