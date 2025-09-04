#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge {
	int u, v; ll cap, cost;
	Edge(int u, int v, ll cap, ll cost) : u(u), v(v), cap(cap), cost(cost) {}
};

struct MCMF {
	const ll INF = numeric_limits<ll>::max();
	int n, src, snk;
	vector<vector<int>> adj;
	vector<Edge> edges;
	vector<ll> dist, pot;
	vector<int> from;

	MCMF(int n, int src, int snk) : n(n), src(src), snk(snk) { adj.resize(n); pot.resize(n); }

	void addEdge(int u, int v, ll cap, ll cost){
		adj[u].push_back(edges.size());
		edges.emplace_back(u, v, cap, cost);

		adj[v].push_back(edges.size());
		edges.emplace_back(v, u, 0, -cost);
	}

	queue<int> q;
	vector<bool> vis;
	bool SPFA(){
		dist.assign(n, INF);
		from.assign(n, -1);
		vis.assign(n, false);

		q.push(src);
		dist[src] = 0;

		while(!q.empty()){
			int u = q.front();
			q.pop();

			vis[u] = false;

			for(auto i : adj[u]){
				if(edges[i].cap == 0) continue;
				int v = edges[i].v;
				ll cost = edges[i].cost;

				if(dist[v] > dist[u] + cost + pot[u] - pot[v]){
					dist[v] = dist[u] + cost + pot[u] - pot[v];
					from[v] = i;
					if(!vis[v]) q.push(v), vis[v] = true;
				}
			}
		}

		for(int u=0; u<n; u++)  //fix pot
			if(dist[u] < INF) 
				pot[u] += dist[u];

		return dist[snk] < INF;
	}

	pair<ll, ll> augment(){
		ll flow = edges[from[snk]].cap, cost = 0; //fixed flow: flow = min(flow, remainder)

		for(int v=snk; v != src; v = edges[from[v]].u)
			flow = min(flow, edges[from[v]].cap), 
			cost += edges[from[v]].cost;
		
		for(int v=snk; v != src; v = edges[from[v]].u)
			edges[from[v]].cap   -= flow,
			edges[from[v]^1].cap += flow;

		return {flow, cost};
	}

	bool inCut(int u){ return dist[u] < INF; }

	pair<ll, ll> maxFlow(){
		ll flow = 0, cost = 0;

		while( SPFA() ){
			auto [f, c] = augment();
			flow += f;
			cost += f*c;
		}
		return {flow, cost};
	}
};
