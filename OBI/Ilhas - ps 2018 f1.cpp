#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vii vector<pair<int,int>>
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;


int main(){

	int n, m;
	cin>>n>>m;

	vii ilha[n+1];

	for(int i=0, u, v, p; i<m; i++)
	{
		cin>>u>>v>>p;
		ilha[u].push_back({v, p});
		ilha[v].push_back({u, p});
	}

	int s; cin>>s;

	//dijkstra
	priority_queue< pii, vii, greater<pii> > fila;
	vi dist(n+1, INF);
	vi vis(n+1, false);

	dist[s] = 0;
	fila.push({0, s});

	while( !fila.empty() )
	{
		int a = fila.top().second;
		fila.pop();

		if(vis[a]) continue;
		vis[a] = true;

		for(auto x : ilha[a])
		{
			int v = x.first;
			int p = x.second;
			if(dist[v] > dist[a] + p)
			{
				dist[v] = dist[a] + p;
				fila.push({dist[v], v});
			}
		}

	}

	sort(ALL(dist));

	cout << dist[dist.size()-2] - dist[1] << endl;
	
	
	return 0;	
}
