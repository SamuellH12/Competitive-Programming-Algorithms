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
vector<vi> grafo;
vi visitado; //tudo 0 por padrão

int dfs(int a, int o)	//a atual / o origem / v visitando 
{
	visitado[a] = 2;
	int par = -1;

	for(auto v : grafo[a])
	{
		if(v == o) continue;
		if(visitado[v] == 1) continue;

		int k = -1;

		if(visitado[v] == 0) k = dfs(v, a);
		else k = v;

		if(k == -1) continue;

		if(par == -1)
		{
			par = k;
		}
		else
		{
			cout<<par<<" "<<a<<" "<<v<<endl;
			par = -1;
		}
	}

	visitado[a] = 1;

	if(par != -1)
	{
		cout<<par<<" "<<a<<" "<<o<<endl;
		return -1;
	}

	return a;
}

int main(){
	cin>>n>>m;

	grafo = vector<vi> (n + 11);
	visitado = vi (n + 11, 0);

	for(int i=0, u, v; i<m; i++)
	{
		cin>>u>>v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	cout<<m/2<<endl;

	dfs(1, -1);

	return 0;	
}

//https://codeforces.com/gym/101064/problem/I