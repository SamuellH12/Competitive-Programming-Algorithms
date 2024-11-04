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
// https://codeforces.com/contest/546/problem/E

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
	int n, m; 
	cin >> n >> m;

	vi a(n), b(n);
	int suma = 0, sumb = 0;
	for(auto &x : a) cin >> x, suma += x;
	for(auto &x : b) cin >> x, sumb += x;

	if(suma != sumb){
		cout << "NO" << endl;
		return 0;
	}

	Dinic fl(n+n+2, 0, n+n+1);

	for(int i=0, u, v; i<m; i++)
	{
		cin >> u >> v;
		fl.addAresta(u, n+v, INF);
		fl.addAresta(v, n+u, INF);
	}

	for(int u=1; u<=n; u++)
		fl.addAresta(u, n+u, INF);

	for(int u=1; u<=n; u++)
		fl.addAresta(0, u, a[u-1]),
		fl.addAresta(u+n, n+n+1, b[u-1]);
	
	if(fl.maxFlow() != suma){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	vector<vector<int>> ans(n, vector<int>(n, 0));

	for(int i=0; i<m+m+n; i++){
		auto [v, u, c] = fl.arestas[i*2+1];
		ans[u-1][v-n-1] = c;
	}

	for(auto &v : ans){
		for(auto &x : v)
			cout << x << " ";
		cout << endl;
	}

	return 0;	
}
