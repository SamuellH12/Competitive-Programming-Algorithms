#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
const int MAXN = 5 * 1e4 + 5;
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;

// https://cses.fi/problemset/task/2138

int n, m;
vi grafo[MAXN];

bitset<MAXN> memo [MAXN];
bool vis [MAXN];

inline bitset<MAXN> dfs(int u){
	if(vis[u]) return memo[u];

	vis[u] = true;
	memo[u].set(u);

	for(auto v : grafo[u])
		memo[u] |= dfs(v);

	return memo[u];
}

int main(){
	optimize;
	cin >> n >> m;

	for(int i=0, u, v; i<m; i++){
		cin >> u >> v;
		grafo[u].push_back(v);
	}

	for(int i=1; i<=n; i++) cout << dfs(i).count() << " ";
	cout << endl;
	
	return 0;	
}
