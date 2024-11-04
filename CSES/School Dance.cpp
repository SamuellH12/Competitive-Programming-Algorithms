#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
//https://cses.fi/problemset/task/1696/

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
	optimize;
	int n, m, k;
	cin >> n >> m >> k;

	Dinic match(n+m+2, 0, n+m+1);

	for(int i=0,b,g; i<k &&cin>>b>>g; i++) match.addAresta(b, g+n, 1);
	for(int b=1; b<=n; b++) match.addAresta(0, b, 1);
	for(int g=1; g<=m; g++) match.addAresta(g+n, n+m+1, 1);
	
	cout << match.maxFlow() << endl;

	for(int i=0; i<k; i++)
		if(match.arestas[i*2].cap == 0)
			cout << match.arestas[i*2].u << " " << match.arestas[i*2].v-n << endl;

	return 0;	
}
