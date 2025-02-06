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

//https://neps.academy/br/exercise/1008
//para: MAIOR NUMERO DE SALÕES

vi arestas [220];
bool visitados[220];
int alts[220];
int ans = 0;

void dfs(int u){

	visitados[u] = true;
	
	ans++;

	for(int v : arestas[u]){
		if(!visitados[v])
			dfs(v);
	}

}
  

int main(){
	int ns, nt, si;
	cin>>ns>>nt>>si;

	for(int i=1; i<=ns; i++)
		cin>>alts[i];

	for(int i=0; i<nt; i++){
		int u, v;
		cin>>u>>v;

		if(alts[u]>alts[v])
			arestas[u].push_back(v);
		else
			arestas[v].push_back(u);

	}

	memset(visitados, 0, sizeof(visitados));

	dfs(si);
	cout<<ans - 1<<endl;

	return 0;	
}
