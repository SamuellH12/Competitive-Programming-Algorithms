#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 1010
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://codeforces.com/gym/102021

vector<pii> grafo [MAXN];
int memo[MAXN];

int dfs(pii g)
{
	int v = g.first;
	if(memo[v] != -1) return memo[v];

	int resp = 0;

	for(auto x : grafo[v])
			resp = max(resp, x.second + dfs(x));

	return memo[v] = resp;
}


int main(){

	int n, m;
	cin>>n>>m;

	for(int i=0; i<n+10; i++) memo[i] = -1;

	for(int i=0, u, v, c; i<m; i++)
	{
		cin>>u>>v>>c;
		grafo[u].emplace_back(v, c);
	}

	int resp = 0;

	for(int i=1; i<=n; i++)
	{
		for(auto v : grafo[i])
			resp = max(resp, v.second + dfs(v));
	}
		
	cout<<resp<<endl;

	return 0;	
}
