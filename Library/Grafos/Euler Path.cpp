#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

const int MAXN = 1e6 + 5;
const bool BIDIRECIONAL = true;

vector<pii> grafo[MAXN];
vector<bool> used;

void addEdge(int u, int v){
	grafo[u].emplace_back(v, used.size());
	if(BIDIRECIONAL && u != v) 
		grafo[v].emplace_back(u, used.size());	

	used.emplace_back(false);
}

// !!! verifique se o grafo é conexo !!!
vector<int> EulerPath(int n, int src=0){
	int s=-1, t=-1;

	if(BIDIRECIONAL)
	{
		for(int u=0; u<n; u++)	
			if(grafo[u].size()%2)
				if(t != -1) return vector<int>();    // mais que 2 com grau ímpar
				else t = s, s = u;

		if(t == -1 && t != s) return vector<int>(); // só 1 com grau ímpar
		if(s == -1 || t == src) s = src;            // se possivel, seta start como src
	}
	else
	{
		vector<int> in(n, 0), out(n, 0);

		for(int u=0; u<n; u++)
			for(auto [v, edg] : grafo[u]) 
				in[v]++, out[u]++;

		for(int u=0; u<n; u++){
			if(in[u] == out[u]) continue;
			if(in[u] - out[u] == -1 && s == -1) s = u;  else
			if(in[u] - out[u] ==  1 && t == -1) t = u;  else 
			return vector<int>();
		}
	
		if(s == -1 && t == -1) s = t = src;           // se possivel, seta s como src
		if(s == -1  && t != -1) return vector<int>(); // Existe S mas não T 
		if(s != -1  && t == -1) return vector<int>(); // Existe T mas não S
	}

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
	return path;	  // Vertex List
}
/**************************************
	Euler Path
Algoritmo de Hierholzer para encontrar caminho Euleriano (Euler Path) em um grafo

CUIDADO! Com grafos Desconexos. Verificar se SORCE é válido!!!
CUIDADO! Com Self Loops
IMPORTANTE! O algoritmo está 0-indexado

Complexity: O(V + E)

* Informações
	addEdge(u, v) -> Adiciona uma aresta de U para V
	EulerPath(n, s) -> Retorna o Euler Path partindo de S, ou um vetor vazio se impossível
	vi path -> Lista de vértices do Euler Path na ordem REVERSA a que são visitados
	vi pathId -> id das Arestas do Euler Path na ordem REVERSA a que são visitadas
**************************************/
/**************************************
Para saber se um grafo possui um Caminho Euleriano:

Undirected graph:
	- Cada vértice deve ter um número par de arestas (circuito); OU
	- Exatamente dois vértices devem ter um número ímpar de arestas (caminho);

Directed graph:
	- Cada vértice deve ter a mesma quantidade de arestas de entrada e de saída (circuito); OU
	- Exatamente um vértice deve ter uma aresta de entrada a mais e exatemente um vértice deve ter uma aresta de saída a mais (caminho);

 * Circuito -> Sai do vértice U e retorna ao mesmo vértice no final
 * Caminho -> Sai de um vértice U e chega em um vértice V no final
**************************************/
int main(){}