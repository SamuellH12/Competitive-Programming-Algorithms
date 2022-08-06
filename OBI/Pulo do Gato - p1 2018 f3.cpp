#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 505
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;
#define vii vector<pii>

int matriz[MAXN][MAXN], l, c;
bool vis[MAXN][MAXN];

vii caminho(int x, int y){
	vii caminhos;

	for(int i=x-2; i<=x+2; i++){      
		if(i < 1 || i > l ) continue;

		for(int e=y-2; e<=y+2; e++){  
			if(e < 1 || e > c || (e == y && x==i)) continue;

			if(matriz[i][e] == 1)
				caminhos.emplace_back(i, e);
		}
	}

	return caminhos;
}

int bfs(int a, int b)
{
	queue<pii> fila;
	queue<int> dist;
	fila.push({a, b});
	dist.push(0);

	while(!fila.empty())
	{
		int x = fila.front().first;
		int y = fila.front().second;
		int d = dist.front();
		fila.pop(); dist.pop();

		if(x==l && y==c) return d;

		if(vis[x][y]) continue;
		vis[x][y] = true;

		vii caminhos = caminho(x, y);

		for(auto pulo : caminhos){
			fila.push(pulo);
			dist.push(d+1);
		}

	}

	return -1;
}


int main()
{
	cin>>l>>c;

	for(int i=1; i<=l; i++)
		for(int e=1; e<=c; e++)
			cin>>matriz[i][e];
	
	int resp = bfs(1, 1);

	cout<<resp<<endl;

	return 0;	
}

/* PULO DO GATO - OBI 2018 - 3 fase
https://olimpiada.ic.unicamp.br/pratique/p1/2018/f3/gato/

COM BFS
100 de 100 pontos
Acredito que estou chegando a conclusão de que,
no bfs, a primeira aparição de um vértice é 
sempre sua menor distância, para grafos não
ponderados, claro.


QUANDO TENTEI COM DFS
40 de 100 pontos (nenhum TLE)
Acredito que o DP pode não estar armazenando 
a menor distância sempre, por isso WA em alguns
casos de teste.

*/