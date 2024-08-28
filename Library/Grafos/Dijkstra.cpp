#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
#define INF 0x3f3f3f3f
#define vi vector<int>
#define pii pair<int,int>

vector<pii> grafo [MAXN];

vi dijkstra(int s){
	vi dist (MAXN, INF); // !!! Change MAXN to N

	priority_queue<pii, vector<pii>, greater<pii>> fila;
	fila.push({0, s});
	dist[s] = 0;

	while(!fila.empty())
	{
		auto [d, u] = fila.top();
		fila.pop();

		if(d > dist[u]) continue;

		for(auto [v, c] : grafo[u])
			if( dist[v] > dist[u] + c )
			{
				dist[v] = dist[u] + c;
				fila.push({dist[v], v});
			}
	}

	return dist;
}
/**************************************
Dijkstra - Shortest Paths from Source

caminho minimo de um vertice u para todos os
outros vertices de um grafo ponderado

Complexity: O(N Log N)

dijkstra(s)				->  s : Source, Origem. As distancias serao calculadas com base no vertice s
grafo[u] = {v, c};  	->  u : Vertice inicial, v : Vertice final, c : Custo da aresta
priority_queue<pii, vector<pii>, greater<pii>> ->  Ordena pelo menor custo -> {d, v} -> d : Distancia, v : Vertice
***************************************/