#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 10010
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p1/2017/f3/visita/

#define aresta first
#define custo second

vector<pii> grafo[MAXN];
int n, o, d, resp = 0;

bool dfs(int atual, int pai){
	if(atual == d) return true;
	
	for(auto a : grafo[atual])
		if(a.aresta != pai && dfs(a.aresta, atual))
		{
			resp += a.custo;
			return true;
		}

	return false;
}

int main(){
	cin>>n>>o>>d;

	for(int i=1; i<n; i++)
	{
		int u, v, c;
		cin>>u>>v>>c;

		grafo[u].emplace_back(v, c);
		grafo[v].emplace_back(u, c);
	}
	
	dfs(o, 0);

	cout<<resp<<endl;

	return 0;	
}
