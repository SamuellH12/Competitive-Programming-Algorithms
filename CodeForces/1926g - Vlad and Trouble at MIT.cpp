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
//https://codeforces.com/contest/1926/problem/G

vi grafo[MAXN];
int tp[MAXN], memo[MAXN][2];

int solve(int u, int p, int t){
	if(~memo[u][t]) return memo[u][t];
	if((tp[u]^1) == t) return memo[u][t] = INF;

	int ans = 0;

	for(auto v : grafo[u])
		if(v != p)
			ans += min(solve(v, u, 1) + (t!=1), solve(v, u, 0) + (t!=0));

	return memo[u][t] = ans;
}

int main(){
	optimize;
	int t; cin >> t;
	while(t--){
		
		int n; cin >> n;

		for(int i=0; i<=n; i++) grafo[i].clear(), memo[i][0] = memo[i][1] = -1;

		for(int u=2, v; u<=n; u++)
		{
			cin >> v;
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}

		string s; cin >> s;
		for(int i=0; i<n; i++) 
			if(s[i] == 'P') tp[i+1] = 0;
			else
			if(s[i] == 'S') tp[i+1] = 1;
			else tp[i+1] = 2;

		int ans = min(solve(1, 0, 0), solve(1, 0, 1));

		cout << ans << endl;
	}
	
	return 0;	
}
