#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;

//1152 - Estradas Escuras 
//DSU

struct Aresta{
	int u, v, c;

	Aresta(int u=0, int v=0, int c=0) : u(u), v(v), c(c) {}

	bool operator < (const Aresta a) const
	{
		return a.c > c;
	}
};

int n, m;
vector<Aresta> arestas; 
vi chefe;
vi sz;

int achaChefe(int u)
{
	return chefe[u] = (chefe[u] == u ? u : achaChefe(chefe[u]));
}

void join(int u, int v)
{
	u = achaChefe(u);
	v = achaChefe(v);
	if(u == v) return; //mesmo chefe

	if(sz[u] > sz[v]) swap(u, v); //o u vai ser sempre o menor, isso otimiza MUUITO!!!
	chefe[u] = v; 
	sz[v] += sz[u]; //o tamanho do v agora é o tamanho dele + do u
}

int kruskal()
{
	int resp = 0;

	for(auto a : arestas)
		if(achaChefe(a.u) != achaChefe(a.v))
		{
			join(a.u, a.v);
			resp += a.c;
			if(sz[achaChefe(a.u)] >= m) break;
		}

	return resp;
}


int main(){
	optimize;

	while( cin>>m>>n && (m+n) )
	{
		arestas.clear();

		ll total = 0;

		int u, v, c;
		while(n--)
		{
			cin>>u>>v>>c;
			arestas.emplace_back(Aresta(u, v, c));
			total += c;
		}

		sort(ALL(arestas));
		chefe = vi (m+1);
		sz = vi(m+1, 1);
		iota(ALL(chefe), 0);

		total -= kruskal();

		cout<<total<<endl;
	}


	return 0;	
}
