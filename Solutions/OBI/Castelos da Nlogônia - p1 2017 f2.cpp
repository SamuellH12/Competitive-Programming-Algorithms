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


int n, m;
vi caminhos[MAXN], camemo; 	//caminho[] é uma lista de adjacências   e  camemo é a lista de castelos entre p e q
int castelos[MAXN]; 		//castelos[] é a cor de cada castelo
bool visitados[MAXN];



bool AchaCaminho(int atual, int q)
{
		if(visitados[atual]) return false;
		visitados[atual] = true;
		
		camemo.push_back(atual);          //adiciona o vértice atual ao caminho

		if(atual == q) return true;

		for(int a : caminhos[atual])              	//faz uma dfs
			if(AchaCaminho(a, q)) return true;

		camemo.pop_back();							//se não encontrar q, remove o atual do caminho
		return false;

}


void pintor(int c){
	//pinta todos no caminho memorizado com a cor
	for(auto cast : camemo)
		castelos[cast] = c;
}


int main(){

	optimize;
	//inicializa todas as cores como 0
	memset(castelos, 0, sizeof(castelos));

	cin>>n>>m;

	//adiciona as arestas
	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin>>u>>v;

		caminhos[u].push_back(v);
		caminhos[v].push_back(u);
	}
	

	//encontra os caminhos e pinta para cada cor;
	for(int i=0; i<m; i++)
	{
		memset(visitados, false, sizeof(visitados));
		camemo.clear();

		int p, q, c;
		cin>>p>>q>>c;

		AchaCaminho(p, q);
		
		pintor(c);
	}


	//imprime a lista de cores
	for(int i=1; i<=n; i++)
		cout<<castelos[i]<<" ";

	return 0;	
}
