#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Aresta {
	int u, v; ll cap;
	Aresta(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};

struct Dinic {

	int n, source, sink;
	vector<vector<int>> adj;
	vector<Aresta> arestas;
	vector<int> level, ptr; //pointer para a próxima aresta não saturada de cada vértice

	Dinic(int n, int source, int sink) : n(n), source(source), sink(sink) { adj.resize(n); }

	void addAresta(int u, int v, ll cap)
	{
		adj[u].push_back(arestas.size());
		arestas.emplace_back(u, v, cap);

		adj[v].push_back(arestas.size());
		arestas.emplace_back(v, u, 0);
	}

	ll dfs(int u, ll flow = 1e9){
		if(flow == 0) return 0;
		if(u == sink) return flow;

		for(int &i = ptr[u];  i < adj[u].size();  i++)
		{
			int atual = adj[u][i];
			int v = arestas[atual].v;

			if(level[u] + 1 != level[v]) continue;

			if(ll got = dfs(v, min(flow, arestas[atual].cap)) )
			{
				arestas[atual].cap -= got;
				arestas[atual^1].cap += got;
				return got;
			}
		}

		return 0;
	}

	bool bfs(){
		level = vector<int> (n, n);
		level[source] = 0;

		queue<int> fila;
		fila.push(source);

		while(!fila.empty())
		{
			int u = fila.front();
			fila.pop();

			for(auto i : adj[u]){
				int v = arestas[i].v;

				if(arestas[i].cap == 0 || level[v] <= level[u] + 1 ) continue;

				level[v] = level[u] + 1;
				fila.push(v);
			}
		}

		return level[sink] < n;
	}

	bool inCut(int u){ return level[u] < n; }

	ll maxFlow(){
		ll ans = 0;

		while( bfs() ){
			ptr = vector<int> (n+1, 0);

			while(ll got = dfs(source)) ans += got;
		}

		return ans;
	}
};
/**************************************
    Dinic - Max Flow Min Cut
Algoritmo de Dinitz para encontrar o Fluxo Máximo
IMPORTANTE! O algoritmo está 0-indexado

Complexity:
O( V^2 * E )      ->  caso geral
O( sqrt(V) * E )  ->  grafos com cap = 1 para toda aresta // matching bipartido

* Informações:
	Crie o Dinic:
		Dinic dinic(n, source, sink);
	Adicione as Arestas:
		dinic.addAresta(u, v, capacity);
	Para calcular o Fluxo Máximo:
		dinic.maxFlow()
	Para saber se um vértice U está no Corte Mínimo:
		dinic.inCut(u)

* Sobre o Código:
	vector<Aresta> arestas;  -> Guarda todas as arestas do grafo e do grafo residual
	vector<vector<int>> adj; -> Guarda em adj[u] os índices de todas as arestas saindo de u
	vector<int> ptr;   ->  Pointer para a próxima aresta ainda não visitada de cada vértice
	vector<int> level; -> Distância em vértices a partir do Source. Se igual a N o vértice não foi visitado.
	A BFS retorna se Sink é alcançavel de Source. Se não é porque foi atingido o Fluxo Máximo
	A DFS retorna um possível aumento do Fluxo
***************************************/
/**************************************
* Use Cases of Flow
	   
+ Minimum cut: the minimum cut is equal to maximum flow.
  i.e. to split the graph in two parts, one on the source side and another on sink side.
  The capacity of each edge is it weight.

+ Edge-disjoint paths: maximum number of edge-disjoint paths equals maximum flow of the
  graph, assuming that the capacity of each edge is one. (paths can be found greedily)

+ Node-disjoint paths: can be reduced to maximum flow. each node should appear in at most one 
  path, so limit the flow through a node dividing each node in two. One with incoming edges,
  other with outgoing edges and a new edge from the first to the second with capacity 1.

+ Maximum matching (bipartite): maximum matching is equal to maximum flow. Add a source and
  a sink, edges from the source to every node at one partition and from each node of the 
  other partition to the sink.

+ Minimum node cover (bipartite): minimum set of nodes such each edge has at least one 
  endpoint. The size of minimum node cover is equal to maximum matching (Konig’s theorem).

+ Maximum independent set (bipartite): largest set of nodes such that no two nodes are 
  connected with an edge. Contain the nodes that aren't in "Min node cover" (N - MAXFLOW).

+ Minimum path cover (DAG): set of paths such that each node belongs to at least one path. 
  - Node-disjoint: construc a matching where each node is represented by two nodes, a left and 
    a right at the matching and add the edges (from l to r). Each edge in the matching
    corresponds to an edge in the path cover. The number of paths in the cover is (N - MAXFLOW).
  - General: almost like a minimum node-disjoint. Just add edges to the matching whenever there 
    is an path from U to V in the graph (possibly through several edges).
  - Antichain: a set of nodes such that there is no path from any node to another. In a DAG, the 
    size of min general path cover equals the size of maximum antichain (Dilworth’s theorem).
***************************************/