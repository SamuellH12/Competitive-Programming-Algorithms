#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://www.spoj.com/problems/PT07Z/en/

int n;
vi grafo[MAXN];
int memo[MAXN][2];

int dfs(int u, int p, bool caso)
{
	int &resp = memo[u][caso];

	if(resp == -1) //retorna memo como resp no final, se já houver calculado ele antes, ou seja != -1
	{
		resp = 0;

		if(caso == 0) //não comecei o diâmetro
		{
			for(auto v : grafo[u]) //chamar meus filhos tb sem começar
				if(v!=p)
					resp = max(resp, dfs(v, u, 0));

			int top=0, top2=0;
			for(auto v : grafo[u]) //ou chamar começando por mim
				if(v!=p)
				{
					int val = dfs(v, u, 1) + 1;

					if(val > top2) top2 = val;

					if(top2 > top) swap(top, top2);
				}
			resp = max(resp, top+top2);
		}
		else //caso 1, faço parte do diâmetro
		{
			for(auto v : grafo[u])
				if(v!=p)
					resp = max(resp, 1+dfs(v, u, 1));
		}

	}

	return resp;
}

int main(){
	cin>>n;

	for(int i=0; i<=n; i++){ memo[i][0] = -1; memo[i][1] = -1; }

	for(int i=1, u, v; i<n; i++)
	{
		cin>>u>>v;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	cout<<dfs(1, 0, 0)<<endl;

	return 0;	
}

//https://vjudge.net/contest/478241#problem/C