#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define vi vector<int>
#define pii pair<int,int>

const int MAXN = 1e6 + 5;

vector<pii> grafo [MAXN];

vi dijkstra(int s){
	vi dist (MAXN, INF);

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


int main(){
	cout << "Dijkstra - Shortest Paths from Source" << endl;
	return 0;
}


/**************************************
Algoritmo para encontrar o caminho 
minimo de um vertice u para todos os
outros vertices de um grafo qualquer

Complexity:
O(N Log N)

dijkstra(s)				->  s : Source, Origem. As distancias serao calculadas com base no vertice s
grafo[u] = {v, c};  	->  u : Vertice inicial, v : Vertice final, c : Custo da aresta
priority_queue<pii, vector<pii>, greater<pii>> ->  Ordena pelo menor custo -> {d, v} -> d : Distancia, v : Vertice
***************************************/