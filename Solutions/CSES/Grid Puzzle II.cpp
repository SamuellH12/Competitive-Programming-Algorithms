#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
const int MAXN = 1e6 + 5;
using namespace std;
// https://cses.fi/problemset/task/2131/

struct Aresta {
	int u, v; ll cap, cost;
	Aresta(int u, int v, ll cap, ll cost) : u(u), v(v), cap(cap), cost(cost) {}
};

struct MCMF {
	const ll INF = numeric_limits<ll>::max();
	int n, source, sink;
	vector<vector<int>> adj;
	vector<Aresta> edges;
	vector<ll> dist, pot;
	vector<int> from;

	MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) { adj.resize(n); pot.resize(n); }

	void addAresta(int u, int v, ll cap, ll cost)
	{
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

		q.push(source);
		dist[source] = 0;

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

		return dist[sink] < INF;
	}

	pair<ll, ll> augment(){
		ll flow = edges[from[sink]].cap, cost = 0; //for fixed max flow, change this

		for(int v=sink; v != source; v = edges[from[v]].u)
			flow = min(flow, edges[from[v]].cap), 
			cost += edges[from[v]].cost;
		
		for(int v=sink; v != source; v = edges[from[v]].u)
			edges[from[v]].cap   -= flow,
			edges[from[v]^1].cap += flow;

		return {flow, cost};
	}

	bool inCut(int u){ return dist[u] < INF; }

	pair<ll, ll> maxFlow(){
		ll flow = 0, cost = 0; // fixPot();

		while( SPFA() ){
			auto [f, c] = augment();
			flow += f;
			cost += f*c;
		}

		return {flow, cost};
	}
};


int main(){
	optimize;
	int n; cin >> n;

	int src = n*n+n+n, snk = n*n+n+n+1, c, sum=0;
	MCMF flw(n*n+n+n+2, src, snk);

	for(int i=0, m; i<n; i++)
	{
		cin >> m; sum += m;
		flw.addAresta(src, n*n+i, m, 0);
	}

	for(int j=0, m; j<n; j++)
	{
		cin >> m;
		flw.addAresta(n*n+n+j, snk, m, 0);
	}

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++){
			cin >> c;
			flw.addAresta(n*n+i, i*n+j,  1, -c);
			flw.addAresta(i*n+j, n*n+n+j, 1, 0);
		}


	auto [f, cs] = flw.maxFlow();
	if(f != sum){
		cerr << f << " ";
		cout << -1 << endl;
		return 0;
	}

	cout << -cs << endl;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			if(flw.edges[2*(n+n) +  4*(i*n+j)].cap == 0) cout << 'X';
			else cout << '.';
		cout << endl;
	}

	return 0;	
}
