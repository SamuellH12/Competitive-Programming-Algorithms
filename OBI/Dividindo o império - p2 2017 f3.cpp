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
//https://olimpiada.ic.unicamp.br/pratique/p2/2017/f3/imperio/

int n;
vi grafo[MAXN];
int sz[MAXN];

int dfs(int u, int p)
{
	sz[u] = 1;	

	for(auto v : grafo[u])
		if(v != p)
			sz[u] += dfs(v, u);
			
	return sz[u];
}


int main(){
	cin >> n;

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	dfs(1, 0); 

	int mn = INF;
	for(auto x : sz)
		mn = min(mn, abs(n - x - x ));

	cout << mn << endl;
	
	return 0;	
}

/*
	Super estimei a questão... 
	Fiquei meia hora achando que era achar o centroid e depois o maior galho
	Mas era só pegar o tamanho das sub-árvores mesmo e já resolvia, embora eu ainda não 
tenha entendido o pq do centroid não funcionar :thinking_emoji:
*/