#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define piii pair<int,pii>
#define INF 0x3f3f3f3f
const int MAXN = 5 * 1e3 + 5;
using namespace std;

// https://neps.academy/br/exercise/2132
// dijkstra

struct path { int v, t, p; };

vector<path> grafo[MAXN];
int dist[205][MAXN];


int main(){
	optimize;
	memset(dist, INF, sizeof dist);
	int n, m, VM;
	cin >> VM >> n >> m;
	
	map<int, int> mp;
	
	for(int i=0, u, v, t, p; i<m; i++)
	{
		cin >> u >> v >> t >> p;
		if(!mp.count(u)) mp[u] = mp.size();
		if(!mp.count(v)) mp[v] = mp.size();

		u = mp[u], v = mp[v];

		grafo[u].push_back({v, t, p});
		grafo[v].push_back({u, t, p});
	}

	int s, d;
	cin >> s >> d;
	
	if(!mp.count(s)) mp[s] = mp.size();
	if(!mp.count(d)) mp[d] = mp.size();

	s = mp[s], d = mp[d];

	priority_queue<piii, vector<piii>, greater<piii>> fila;
	fila.push({0, pii(s, 0)});
	dist[0][s] = 0;

	while(!fila.empty())
	{
		auto [d, uc] = fila.top();
		auto [u, c] = uc;
		fila.pop();

		if(d > dist[c][u]) continue;

		for(auto [v, t, p] : grafo[u])
			if( c+p <= VM && dist[c+p][v] > dist[c][u] + t )
			{
				dist[c+p][v] = dist[c][u] + t;
				fila.push({dist[c+p][v], pii(v, c+p)});
			}
	}


	int mn = INF;
	for(int i=0; i<=VM; i++)
		mn = min(mn, dist[i][d]);


	cout << (mn < INF ? mn : -1) << endl;

	return 0;	
}
