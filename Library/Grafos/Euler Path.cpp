#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define vi vector<int>

const int MAXN = 1e6 + 5; //LATEX_IGNORED_LINE
const bool BIDIRECIONAL = true;
vector<pii> g [MAXN];
vector<bool> used;

void addEdge(int u, int v){
	g[u].emplace_back(v, used.size()); if(BIDIRECIONAL && u != v) 
	g[v].emplace_back(u, used.size());	
	used.emplace_back(false);
}

pair<vi, vi> EulerPath(int n, int src=0){
	int s=-1, t=-1;
	vector<int> selfLoop(n*BIDIRECIONAL, 0);

	if(BIDIRECIONAL)
	{
		for(int u=0; u<n; u++) for(auto&[v, id] : g[u]) if(u==v) selfLoop[u]++;
		for(int u=0; u<n; u++)
			if((g[u].size() - selfLoop[u])%2)
				if(t != -1) return {vi(), vi()};   // mais que 2 com grau ímpar
				else t = s, s = u;
		
		if(t == -1 && t != s) return {vi(), vi()}; // só 1 com grau ímpar
		if(s == -1 || t == src) s = src;           // se possivel, seta start como src
	}
	else
	{
		vector<int> in(n, 0), out(n, 0);

		for(int u=0; u<n; u++)
			for(auto [v, edg] : g[u]) 
				in[v]++, out[u]++;

		for(int u=0; u<n; u++)
			if(in[u] - out[u] == -1 && s == -1) s = u;  else
			if(in[u] - out[u] ==  1 && t == -1) t = u;  else 
			if(in[u] !=out[u]) return {vi(), vi()};
	
		if(s == -1 && t == -1) s = t = src;         // se possivel, seta s como src
		if(s == -1 && t != -1) return {vi(), vi()}; // Existe S mas não T 
		if(s != -1 && t == -1) return {vi(), vi()}; // Existe T mas não S
	}

	for(int i=0; g[s].empty() && i<n; i++) s =(s+1)%n; //evita s ser vértice isolado

	/////// DFS ///////
	vector<int> path, pathId, idx(n, 0);
	stack<pii> st; // {Vertex, EdgeId}
	st.push({s, -1});

	while(!st.empty()){
		auto [u, edg] = st.top();
		while(idx[u] < g[u].size() && used[g[u][idx[u]].second]) idx[u]++;

		if(idx[u] < g[u].size()){
			auto [v, id] = g[u][idx[u]];
			used[id] = true;
			st.push({v, id});
			continue;
		}
		
		path.push_back(u);
		pathId.push_back(edg);
		st.pop();
	}

	pathId.pop_back();
	reverse(begin(path),   end(path));
	reverse(begin(pathId), end(pathId));
	
	///  Grafo conexo ? ///
	int edgesTotal = 0;
	for(int u=0; u<n; u++) edgesTotal += g[u].size() + (BIDIRECIONAL ? selfLoop[u] : 0);
	if(BIDIRECIONAL) edgesTotal /= 2;
	if(pathId.size() != edgesTotal) return {vi(), vi()}; 
	//////////////////////

	return {path, pathId};
}


/*LATEX_DESC_BEGIN***************************
**Euler Path** - Algoritmo de Hierholzer para caminho Euleriano - O(V + E)
IMPORTANTE! O algoritmo está 0-indexado

* Informações
	addEdge(u, v) -> Adiciona uma aresta de U para V
	EulerPath(n) -> Retorna o Euler Path, ou um vetor vazio se impossível
	vi path -> vértices do Euler Path na ordem
	vi pathId -> id das Arestas do Euler Path na ordem

Euler em Undirected graph:
	- Cada vértice tem um número par de arestas (circuito); OU
	- Exatamente dois vértices têm um número ímpar de arestas (caminho);
Euler em Directed graph:
	- Cada vértice tem quantidade de arestas |entrada| == |saída| (circuito); OU
	- Exatamente 1 tem |entrada|+1 == |saída| && exatamente 1 tem |entrada| == |saída|+1 (caminho);
* Circuito -> U é o primeiro e último 
* Caminho  -> U é o primeiro e V o último
*****************************LATEX_DESC_END*/