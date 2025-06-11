#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
const int BLOCK_SZ = 500;
struct Query{int l, r, idx;}; //same of MO. Copy operator <

vector<int> g[MAXN];
int tin[MAXN], tout[MAXN];
int pai[MAXN], order[MAXN];

void remove(int u);
void add(int u);
int getAnswer();

void go_to(int ti, int tp, int otp){
	int u = order[ti], v, to;
	to = tout[u];
	while(!(ti <= tp && tp <= to)){ //subo com U (ti) até ser ancestral de W
		v = pai[u];

		if(ti <= otp && otp <= to) add(v);
		else remove(u);

		u = v;
		ti = tin[u];
		to = tout[u];
	}

	int w = order[tp]; 
	to = tout[w];
	while(ti < tp){ //subo com W (tp) até U
		v = pai[w];

		if(tp <= otp && otp <= to) remove(v);
		else add(w);

		w = v;
		tp = tin[w];
		to = tout[w];
	}
}

int TIME = 0;
void dfs(int u, int p){
	pai[u] = p;
	tin[u] = TIME++;
	order[tin[u]] = u;
	
	for(auto v : g[u])
		if(v != p)
			dfs(v, u);
	tout[u] = TIME-1;
}

vector<int> MO(vector<Query> &queries){
	vector<int> ans(queries.size());
	dfs(0, 0);

	for(auto &[u, v, i] : queries)
		tie(u, v) = minmax(tin[u], tin[v]);	
	sort(queries.begin(), queries.end());

	add(0);
	int Lm = 0, Rm = 0;
	for(auto [l, r, idx] : queries){
		if(l < Lm) go_to(Lm, l, Rm), Lm = l;
		if(r > Rm) go_to(Rm, r, Lm), Rm = r;
		if(l > Lm) go_to(Lm, l, Rm), Lm = l;
		if(r < Rm) go_to(Rm, r, Lm), Rm = r;
		ans[idx] = getAnswer();
	}

	return ans;
}
/**************************************
Algoritmo de MO para query de caminho em árvore
Complexity: O((N + Q) * SQRT(N) * F) | F é a complexidade do Add e Remove
IMPORTANTE! 0-indexado!
***************************************/