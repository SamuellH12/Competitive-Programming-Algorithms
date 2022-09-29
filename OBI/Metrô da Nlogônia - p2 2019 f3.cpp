#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2019/f3/metro/
//Adaptada para o Neps Academy
//https://neps.academy/br/exercise/570

int c, q;
vi grafo[2][MAXN];
int dist[2][MAXN];
int  pai[2][MAXN];

inline void dfs(int u, int p, int e)
{
	for(auto v : grafo[e][u])
	{
		if(v == p) continue;

		dist[e][v] = dist[e][u] + 1;
		pai[e][v] = u;

		dfs(v, u, e);
	}
}


inline int center(int u, int v, int e)
{

	int x = v, qtd = 0, meta = dist[e][v]/2;
	if(dist[e][v]%2) meta++; //garantir que vai pegar sempre o centro mais longe (no caso de haver dois centros)

	while(true)
	{
		if( qtd == meta ) 
			return x;

		x = pai[e][x]; qtd++;
	}

	return -1;
}


int main(){
	optimize;
	cin >> c >> q;
	
	for(int i=1, u, v; i<c; i++)
	{
		cin >> u >> v;
		grafo[0][u].push_back(v);
		grafo[0][v].push_back(u); //circulo
	}

	for(int i=1, u, v; i<q; i++)
	{
		cin >> u >> v;
		grafo[1][u].push_back(v);
		grafo[1][v].push_back(u); //quadrado
	}


	///////  Tree Diameter ////////

	dfs(1, -1, 0); //circulo
	dfs(1, -1, 1); //quadrado

	int uc, vc, uq, vq, max = -1; 
	for(int i = 1; i<=c; i++)
		if(dist[0][i] > max)
		{
			uc = i;
			max = dist[0][i];
		}

	max = -1;
	for(int i = 1; i<=q; i++)
		if(dist[1][i] > max)
		{
			uq = i;
			max = dist[1][i];
		}

	memset(dist, 0, sizeof dist);

	dfs(uc, -1, 0); //circulo
	dfs(uq, -1, 1); //quadrado

	max = -1;
	for(int i = 1; i<=c; i++)
		if(dist[0][i] > max)
		{
			vc = i;
			max = dist[0][i];
		}

	max = -1;
	for(int i = 1; i<=q; i++)
		if(dist[1][i] > max)
		{
			vq = i;
			max = dist[1][i];
		}
	///// Fim Tree Diameter ////


	cerr << uq << "-"<< vq << "--" << dist[1][3] << endl;
	///// Encontrar o Centro ////

	int circle = center(uc, vc, 0);
	int square = center(uq, vq, 1);

	cout << circle << " " << square << endl;

	return 0;	
}



/*
Essa é uma questão de centro de árvores.

O algoritmo se divide em duas partes, primeiro encontrar o diâmetro da árvore, o que
fazemos na primeira parte, e depois encontramos o centro de cada uma das árvores, 
tanto da estação círculo como da quadrado, e é basicamente isso.

Talvez eu poste depois uma explicação mais detalhada, se não, cê pode me cobrar por isso :)

*/