#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;

//https://codeforces.com/contest/1776/problem/F

int main(){

	int t; cin >> t;

	while(t--)
	{
		int n, m; cin >> n >> m;

		int sz[n+1];
		memset(sz, 0, sizeof sz);
		vector<pii> arestas;

		for(int i=0, u, v; i<m; i++)
		{
			cin >> u >> v;
			sz[u]++; sz[v]++;
			arestas.push_back({u, v});
		}

		int less = 1;

		for(int i=1; i<=n; i++)
			if(sz[less] > sz[i]) 
				less = i;

		if(sz[less] < n-1)
		{
			cout << 2 << endl;

			for(auto [u, v] : arestas)
				cout << (u == less || v == less ? 1 : 2) << " ";
			cout << endl;
		}
		else
		{
			cout << 3 << endl;

			bool ok = false;
			for(auto [u, v] : arestas)
				if(u == less || v == less){
					cout << (ok ? 1 : 2) << " ";
					ok = true;
				} else
					cout << 3 << " ";
				
			cout << endl;
		}

	}
	
	
	return 0;	
}

/*
Pega o vértice com o menor número de arestas
Se ele tiver < n-1 arestas, ou seja, não se conecta com todos os outros vértices
	a resposta pode sempre ser 2, é só colorir todas as arestas que saem desse vértice com outra cor a do resto do grafo
Senão, e ele se conecta a todos os outros
	a resposta sempre é no min 3, a única diferença da resp anterior é que preciso que uma das arestas
	saind o vértice tenha outra cor
*/
