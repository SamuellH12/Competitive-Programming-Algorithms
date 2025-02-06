#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
const int MAXN = 1e2 + 5;
using namespace std;

// https://www.beecrowd.com.br/judge/pt/problems/view/2042

struct vert { int v, f, s; };

int n, m, p, d, B;
vector<vert> grafo[MAXN];

ll memo[MAXN][1005];

ll solve(int u, int b)
{
	if(b < 0) return -INF;
	if(u == d) return 0;
	if(memo[u][b] != -1) return memo[u][b];

	ll ans = -INF;

	for(auto st : grafo[u])
		ans = max(ans, solve(st.v, b - st.s) + st.f);

	return memo[u][b] = ans;
}

int main(){
	memset(memo, -1, sizeof memo);
	cin >> n >> m;
	cin >> p >> d >> B;

	for(int i=0, u, v, f, s; i<m; i++)
	{
		cin >> u >> v >> f >> s;
		grafo[u].push_back({v, f, s});
		grafo[v].push_back({u, f, s});
	}


	ll ans = solve(p, B);


	if(ans >= 0)
		cout << ans << endl;
	else
		cout << -1 << endl;


	return 0;	
}
