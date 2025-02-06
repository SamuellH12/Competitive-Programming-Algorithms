#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 1010
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;

// https://cses.fi/problemset/task/1638

bool mat[MAXN][MAXN];
ll memo[MAXN][MAXN];
ll n; ll resp = 0;

const ll mod = 1e9 + 7;

ll dfs(int x, int y){
	if(!mat[x][y]) return 0;
	if(x == n-1 && y == n-1) return 1;
	if(memo[x][y] != -1) return memo[x][y];

	ll ans = 0;

	if(x < n-1 && mat[x+1][y] ) ans += dfs(x+1, y) % mod;
	if(y < n-1 && mat[x][y+1] ) ans += dfs(x, y+1) % mod;

	return memo[x][y] = ans % mod;
}

int main(){
	cin >> n;
	memset(memo, -1, sizeof memo);

	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j=0; j<n; j++) mat[i][j] = (s[j] == '.' ? 1 : 0);
	}

	cout << dfs(0, 0) % mod << endl;

	return 0;	
}
