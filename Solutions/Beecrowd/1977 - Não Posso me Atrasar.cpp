#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;
//Não Posso me Atrasar - 1977 - URI 

struct PontoTempo{

	string ponto; int tempo;

	PontoTempo(string p="", int t=0)
	{
		ponto = p; 
		tempo = t;
	}

	bool operator < (const PontoTempo &a) const
	{
		return tempo > a.tempo;
	}

};


int x, n, t;
map <string, vector<pair<string, int>> > origem_destinoCusto;
map <string, bool> visitados;
map <string, int> distancias;


void dijkstra(string origem){

	priority_queue<PontoTempo> fila;

	distancias[origem] = 0;
	fila.push(PontoTempo(origem, 0));

	while(!fila.empty())
	{

		string atual = fila.top().ponto;
		fila.pop();
		
		if(visitados[atual]) continue;
		visitados[atual] = true;

		for(auto aresta : origem_destinoCusto[atual])
		{
			string u = aresta.first;
			int c = aresta.second;

			if(distancias[u] > distancias[atual] + c)
			{
				distancias[u] = distancias[atual] + c;
				fila.push(PontoTempo(u, distancias[u]));
			}
		}
	}
}



int main(){
	optimize;

	while(cin>>x>>n>>t && x+n+t > 0){

		origem_destinoCusto.clear();
		
		string u, v; int c;
		for(int i=0; i<n; i++){
			cin>>u>>v>>c;
			origem_destinoCusto[u].emplace_back(v, c);
			distancias[u]=INF;
			distancias[v]=INF;
			visitados[u]=false;
			visitados[v]=false;
		}

		dijkstra("varzea");
		int tempo = distancias["alto"], min=30;

		if(x>30) min=50;

		min += tempo + (17*60);

		int horas = min / 60;
		min = min%60;

		cout<<horas<<":"<<(min<10 ? "0" : "")<<min<<endl;
		cout<<(horas > 18 || (horas==18 && min>0) ? "Ira se atrasar" : "Nao ira se atrasar")<<endl;

	}

	return 0;	
}
