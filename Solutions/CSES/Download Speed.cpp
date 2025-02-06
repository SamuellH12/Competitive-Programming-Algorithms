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
//https://cses.fi/problemset/task/1694



struct Aresta {
	int u, v; ll cap;
	Aresta(int u, int v, ll cap) : u(u), v(v), cap(cap) {}
};


struct Dinic {

	int n, source, sink;
	vector<vector<int>> adj;
	vector<Aresta> arestas;
	vector<int> level, ptr; //pointer para a próxima aresta não saturada de cada vértice


	Dinic(int n, int source, int sink) : n(n), source(source), sink(sink) {
		adj.resize(n);
	}


	void addAresta(int u, int v, ll cap)
	{
		adj[u].push_back(arestas.size());	//aponta para as arestas
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

		return level[sink] < n;	//se sink foi visitado
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

	int n, m; 
	cin >> n >> m;

	Dinic fluxo(n, 0, n-1);

	//cout << a[0].u << " " << a[0].v << " " << a[0].cap << endl;

	for(int i=0, u, v, c; i<m; i++)
	{
		cin >> u >> v >> c;
		fluxo.addAresta(u-1, v-1, c);
	}

	cout << fluxo.maxFlow() << endl;
	
	return 0;	
}
