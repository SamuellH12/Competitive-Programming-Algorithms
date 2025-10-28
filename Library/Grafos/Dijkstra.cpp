#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e6 + 5; //LATEX_IGNORED_LINE
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<ll,ll>

vector<pii> g[MAXN];

vector<ll> dijkstra(int s, int N){
	vector<ll> dist (N, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s});
	dist[s] = 0;

	while(!pq.empty()){
		auto [d, u] = pq.top();
		pq.pop();
		if(d > dist[u]) continue;

		for(auto [v, c] : g[u])
			if( dist[v] > dist[u] + c ){
				dist[v] = dist[u] + c;
				pq.push({dist[v], v});
			}
	}
	return dist;
}
/**************************************
Dijkstra - Shortest Paths from Source -  O(N Log N)
caminho minimo de um vertice u para todos os outros vertices de um grafo ponderado
dijkstra(s)				->  s : Source, Origem. As distancias serao calculadas com base no vertice s
g[u] = {v, c};  	->  u : Vertice inicial, v : Vertice final, c : Custo da aresta
priority_queue<pii, vector<pii>, greater<pii>> ->  Ordena pelo menor custo -> {d, v} -> d : Distancia, v : Vertice
***************************************/