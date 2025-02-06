//URI 1799 "O Rato no Labirinto"
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

int p, l, resp = 0;
map<string, vector<string>> lab;
map<string, bool> visitados;
map<string, int>  dist;

void mazer(string origem)
{
	queue<string> fila;
	fila.push(origem);
	dist[origem] = 0;

	while(!fila.empty())
	{
		string analise = fila.front();
		fila.pop();

		if(visitados[analise]) continue;
		   visitados[analise] = true;

		for(auto destino : lab[analise])
			if( dist[destino] > dist[analise] + 1 )
			{
				dist[destino] = dist[analise] + 1;
				fila.push(destino);
			}
	}

}


int main(){
	cin>>p>>l;

	//leitura
	for(int i=0; i<l; i++)
	{
		string u, v;
		cin>>u>>v;
		lab[u].push_back(v);
		lab[v].push_back(u);	
	}

	//define as variáveis
	for(auto a = lab.begin(); a != lab.end(); a++)
	{
		string key = a->first;
		visitados[key] = false;
		dist[key] = INF;
	}
	
	//chama dijkstra
	mazer("*");

	int ans = dist["Entrada"] + dist["Saida"];
	cout<<ans<<endl;

	return 0;	
}
