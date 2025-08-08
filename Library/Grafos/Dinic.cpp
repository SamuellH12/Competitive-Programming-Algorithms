#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge {
	int u, v; ll cap;
	Edge(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};

struct Dinic {

	int n, src, sink;
	vector<vector<int>> adj;
	vector<Edge> edges;
	vector<int> lvl, ptr; //pointer para a próxima Edge não saturada de cada vértice

	Dinic(int n, int src, int sink) : n(n), src(src), sink(sink) { adj.resize(n); }

	void addEdge(int u, int v, ll cap)
	{
		adj[u].push_back(edges.size());
		edges.emplace_back(u, v, cap);

		adj[v].push_back(edges.size());
		edges.emplace_back(v, u, 0);
	}

	ll dfs(int u, ll flow = 1e9){
		if(flow == 0) return 0;
		if(u == sink) return flow;

		for(int &i = ptr[u];  i < adj[u].size();  i++)
		{
			int at = adj[u][i];
			int v = edges[at].v;

			if(lvl[u] + 1 != lvl[v]) continue;

			if(ll got = dfs(v, min(flow, edges[at].cap)) )
			{
				edges[at].cap -= got;
				edges[at^1].cap += got;
				return got;
			}
		}

		return 0;
	}

	bool bfs(){
		lvl = vector<int> (n, n);
		lvl[src] = 0;

		queue<int> q;
		q.push(src);

		while(!q.empty())
		{
			int u = q.front();
			q.pop();

			for(auto i : adj[u]){
				int v = edges[i].v;

				if(edges[i].cap == 0 || lvl[v] <= lvl[u] + 1 ) continue;

				lvl[v] = lvl[u] + 1;
				q.push(v);
			}
		}

		return lvl[sink] < n;
	}

	bool inCut(int u){ return lvl[u] < n; }

	ll maxFlow(){
		ll ans = 0;

		while( bfs() ){
			ptr = vector<int> (n+1, 0);

			while(ll got = dfs(src)) ans += got;
		}

		return ans;
	}
};
/*LATEX_DESC_BEGIN***************************
    Dinic - Max Flow Min Cut
Algoritmo de Dinitz para encontrar o Fluxo Máximo. 
**Casos de Uso em [Theorems/Flow]**
IMPORTANTE! O algoritmo está 0-indexado

**Complexity:**
O( V^2 * E )      ->  caso geral
O( sqrt(V) * E )  ->  grafos com cap = 1 para toda Edge // matching bipartido

* Informações:
	Crie o Dinic: Dinic dinic(n, src, sink);
	Adicione as edges: dinic.addEdge(u, v, capacity);
	Para calcular o Fluxo Máximo: dinic.maxFlow()
	Para saber se um vértice U está no Corte Mínimo: dinic.inCut(u)

* Sobre o Código:
	vector<Edge> edges;  -> Guarda todas as edges do grafo e do grafo residual
	vector<vector<int>> adj; -> Guarda em adj[u] os índices de todas as edges saindo de u
	vector<int> ptr;   ->  Pointer para a próxima Edge ainda não visitada de cada vértice
	vector<int> lvl; -> Distância em vértices a partir do Source. Se igual a N o vértice não foi visitado.
	A BFS retorna se Sink é alcançavel de Source. Se não é porque foi atingido o Fluxo Máximo
	A DFS retorna um possível aumento do Fluxo
*****************************LATEX_DESC_END*/
/**************************************LATEX_IGNORED_BEGIN
* Use Cases of Flow
	   
+ Minimum cut: the minimum cut is equal to maximum flow.
  i.e. to split the graph in two parts, one on the src side and another on sink side.
  The capacity of each edge is it weight.

+ Edge-disjoint paths: maximum number of edge-disjoint paths equals maximum flow of the
  graph, assuming that the capacity of each edge is one. (paths can be found greedily)

+ Node-disjoint paths: can be reduced to maximum flow. each node should appear in at most one 
  path, so limit the flow through a node dividing each node in two. One with incoming edges,
  other with outgoing edges and a new edge from the first to the second with capacity 1.

+ Maximum matching (bipartite): maximum matching is equal to maximum flow. Add a src and
  a sink, edges from the src to every node at one partition and from each node of the 
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

+ Project selection: Given N projects, each w profit pi, and M machines, each w cost ci. 
  A project requires a set of machines (can be shared). Choose a set that maximizes value 
  of the profit(projects) - the cost(machines). Add an edge (cap pi) from Source to project.
  An edge (cap ci) from machine to Sink. An edge (cap INF) from a project to each machine it 
  requires. ans = SUM(pi) - MAXFLOW. If the edge of a machine is saturated, buy it.

+ Closure Problem (directed graph): Each node has a weight w (+ or -). choose a closure with 
  maximum sum. a closure is a set of nodes such that there is no edge from a node inside
  the set to a node outside. Is a general case of project selection. Original edges with cap INF.
  Add edges from Source to nodes with W > 0; and from nodes with W < 0 to Sink (cap |W|).
LATEX_IGNORED_END***************************************/
