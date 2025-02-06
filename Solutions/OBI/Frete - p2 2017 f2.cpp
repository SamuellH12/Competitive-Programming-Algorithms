#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;

//https://olimpiada.ic.unicamp.br/pratique/p2/2017/f2/frete/
int n, m;
vector<vii> grafo;

int dijkstra(int origem, int destino)
{
	priority_queue<pii, vii, greater<pii> > fila;
	vi distacia (n+1, INF);
	vector<bool> vis (n+1, false);

	distacia[origem] = 0;
	fila.push({0, origem});

	while(!fila.empty())
	{
		int v = fila.top().second;
		fila.pop();

		if( vis[v] ) continue;
		vis[v] = true;

		if(v == destino) return distacia[v];

		for(auto i : grafo[v])
			if(distacia[i.first] > distacia[v] + i.second)
			{
				distacia[i.first] = distacia[v] + i.second;
				fila.push( {distacia[i.first], i.first} );
			}

	}

	return -1;

}

int main(){
	cin >> n >> m;

	grafo = vector<vii> (n+1);
	
	for(int i=0, u, v, c; i<m; i++)
	{
		cin >> u >> v >> c;

		grafo[u].push_back( {v, c} );
		grafo[v].push_back( {u, c} );
	}

	cout << dijkstra(1, n) << endl;

	return 0;	
}
