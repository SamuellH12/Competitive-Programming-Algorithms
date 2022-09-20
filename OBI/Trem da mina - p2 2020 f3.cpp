#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 10010
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2020/f3/trem/

int e, r, tam, resp;
vector<pii> grafo [MAXN];
vi distancia;
bool vis[MAXN];

int ferrovia[MAXN];
void ciclotron(int u, int p, int c)
{
	vis[u] = true;
	ferrovia[u] = c; 												//distancia, na dfs, que percorri do inicio até aqui (Importante para calcular o tamanho dos ciclos)

	for(auto v : grafo[u])
	{
		if(v.first == p) continue;
		
		if(!vis[v.first]) 
			ciclotron(v.first, u, c+v.second);
		else 														//se já foi visitado, então achamos um ciclo
		{
			int ciclo = ferrovia[u]+v.second - ferrovia[v.first];   //o tam do ciclo é igual a dist percorrida até U mais a dist de U pra V (o primeiro elemento do ciclo) menos a dist percorrida até V (portando removendo o caminho que não faz parte do ciclo)
			if(tam <= ciclo && resp > ciclo + 2*distancia[v.first])
				resp = ciclo + 2*distancia[v.first];						//tamanho do ciclo + (2 vezes a dist de ir e voltar ao pai do ciclo)
		}
	}
}

void dijkstra(int inicio)
{
	vi dist(e+1, INF);
	priority_queue<pii, vector<pii>, greater<pii> > fila;
	
	dist[inicio] = 0;
	fila.push({0, inicio});

	while(!fila.empty())
	{
		int u = fila.top().second;
		fila.pop();

		if(vis[u]) continue;
		vis[u] = true;

		for(auto v : grafo[u])
			if( dist[v.first] > dist[u] + v.second )
			{
				dist[v.first] = dist[u] + v.second;
				fila.push({dist[v.first], v.first});
			}
	}

	distancia = dist;
}

int main(){
	cin >> e >> r;

	for(int i=0, u, v, c; i<r; i++)
	{
		cin >> u >> v >> c;
		grafo[u].push_back({v, c});
		grafo[v].push_back({u, c});
	}

	int k, x;
	cin >> k;

	while(k--)
	{
		cin >> x >> tam;
		resp = INF;

		memset(vis, false, sizeof vis);
		dijkstra(x);

		memset(vis, false, sizeof vis);
		ciclotron(x, -1, 0);
		
		if(resp < INF) cout << resp << endl;
		else cout << -1 << endl;
	}
	
	return 0;	
}


/*
	Vou ficar devendo a explicação dessa questão, mas uma hora eu escrevo! (Um dia... quem sabe... (°_°) )
*/