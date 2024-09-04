#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e6 + 5;
const bool BIDIRECIONAL = true;

vector<pii> grafo[MAXN];
vector<bool> used;

void addEdge(int u, int v){
	grafo[u].emplace_back(v, used.size());	if(u != v)//cuidado com self loop
	grafo[v].emplace_back(u, used.size());	
	used.emplace_back(false);
}

//verifique se o grafo é conexo
vector<int> solve(int n, int src=0){
	int s=-1, t=-1;

	for(int u=0; u<n; u++)	
		if(grafo[u].size()%2)
			if(t != -1) return vector<int>();    // mais que 2 com grau ímpar
			else t = s, s = u;

	if(t == -1 && t != s) return vector<int>(); // só 1 com grau ímpar
	if(s == -1 || t == src) s = src;            // se possivel, seta start como src

	/////// DFS ///////
	vector<int> path, pathId, idx(n, 0);
	stack<pii> st; // Vertex, EdgeId
	st.push({s, -1});

	while(!st.empty())
	{
		auto [u, edg] = st.top();
		while(idx[u] < grafo[u].size() && used[grafo[u][idx[u]].second]) idx[u]++;

		if(idx[u] < grafo[u].size())
		{
			auto [v, id] = grafo[u].back();
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

	// return pathId; // Edges ID list
	return path;	// Vertex List
}

/**************************************
	Euler Path in Undirected Graph

IMPORTANTE! O algoritmo está 0-indexado
IMPORTANTE! Lembre de dar reverse(path.begin(), path.end()) após chamar o findPath()

Complexity: O(V + E)

* Informações
	addEdge(u, v) -> Adiciona uma aresta de U para V

	vi path -> Lista de vértices do Euler Path na ordem REVERSA a que são visitados
	vi pathId -> id das Arestas do Euler Path na ordem REVERSA a que são visitadas
**************************************/