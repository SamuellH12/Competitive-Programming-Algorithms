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



int main(){
	cout << "Dinic - Max Flow Min Cut" << endl;
	return 0;	
}


/**************************************
Algoritmo de Dinic ou Dinitz para encontrar
o Fluxo Máximo e Corte Mínimo em um grafo

Complexity:
O( V^2 * E )      ->  Para grafos gerais
O( sqrt(V) * E )  ->  Para grafos com capacidade = 1 para todos os vértices:


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


IMPORTANTE! O algoritmo está 0-indexado

***************************************/
