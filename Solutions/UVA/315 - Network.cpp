#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e3 + 5;
using namespace std;

//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=251

vector<int> grafo [MAXN];
int pre[MAXN], low[MAXN], clk=0;

vector<int> cut;

void tarjan(int u, int p = -1)
{
	pre[u] = low[u] = clk++;
	int chd = 0;
	bool any = false;

	for(auto v : grafo[u])
	{
		if(v == p) continue;

		if(pre[v] == -1)
		{
			tarjan(v, u);

			low[u] = min(low[v], low[u]);

			if(low[v] >= pre[u]) any = true;

			chd++;
		}
		else
			low[u] = min(low[u], pre[v]);
	}

	if(p == -1 && chd >= 2) cut.push_back(u);
	if(p != -1 && any)      cut.push_back(u);

}


int main(){

	int n;
	while(cin >> n && n)
	{
		memset(pre, -1, sizeof pre);
		for(int i=0; i<=n; i++) grafo[i].clear();
		cut.clear();

		int u; string vv;
		while(cin >> u && u != 0)
		{
			getline(cin, vv);

			int v = 0;

			for(auto c : vv)
			{
				if(c == ' ' && v != 0)
				{ 
					grafo[u].push_back(v);
					grafo[v].push_back(u);
					v = 0; 
				}
				else 
				if(c != ' ') 
					v = v*10 + (c - '0');
			}

			if(v != 0) grafo[u].push_back(v), grafo[v].push_back(u);
		}

		tarjan(1);

		cout << cut.size() << endl;
	}
	
	
	return 0;	
}
