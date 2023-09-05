#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e5 + 5;
using namespace std;

// D. Denouncing Mafia
// https://codeforces.com/gym/102346/problem/D

int n, k;
vi grafo[MAXN];
int h[MAXN];
vi caminhos;

int dfs(int u)
{
	for(auto v : grafo[u])
		h[u] = max(h[u], dfs(v));

	h[u]++;

	return h[u];
}

//isso não é HLD de vdd, só tava com preguiça de pensar num nome melhor
void hld(int u, int c, int p=0)
{
	//cerr << u << " - " << c << " | " << p << endl;
	if(grafo[u].size() == 0)
	{
		caminhos.push_back(c);
		return;
	}

	bool ok = true;

	for(auto v : grafo[u])
	{
		if(ok && h[u] == h[v]+1)
		{
			ok = false;
			hld(v, c+1, u);
		}
		else
			hld(v, 1, u);
	}

}


int main(){

	cin >> n >> k;

	for(int u=2, p; u<=n; u++)
	{
		cin >> p;
		grafo[p].push_back(u);
	}


	dfs(1);
	hld(1, 1);
	
	sort(ALL(caminhos));
	reverse(ALL(caminhos));

	//for(auto x : caminhos) cout << x << " "; cout << endl;

	ll ans = 0;
	for(int i=0; i<k; i++)
		ans += caminhos[i];

	cout << ans << endl;

	return 0;	
}
