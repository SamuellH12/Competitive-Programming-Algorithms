#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 50005
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2020/f1/promocao/

vector<pii> grafo[MAXN];
int memo[2][MAXN];

int dfs(int i, int e)
{	
	if(e !=- 1 && memo[e][i] != 0)
		return memo[e][i];
	int resp = 0;

	for(auto x : grafo[i])
		if(e != x.second)
			resp = max(dfs(x.first, x.second), resp);

	if(e != -1) return memo[e][i] = resp + 1; 	//Acusava run time error pq esqueci desse if aqui,
	else return resp + 1;						//Lembrar de verificar memória inválida nos return tb!!!
}

int main(){
	int n; cin>>n;

	for(int i=1, u, v, o; i<n; i++)
	{
		cin>>u>>v>>o;
		grafo[u].push_back({v, o});
		grafo[v].push_back({u, o});
	}
	
	int resp=0;
	for(int i=1; i<=n; i++)
		resp = max(resp, dfs(i, -1));

	cout<<resp<<endl;
	
	return 0;	
}
