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

int n; 
vi pedras;

int memo[MAXN];
int solve(int i){
	if(i >= n) return 0;
	if(memo[i] != -1) return memo[i];

	int resp = solve(i+1) + abs(pedras[i] - pedras[min(n-1, i+1)]);
	int ans  = solve(i+2) + abs(pedras[i] - pedras[min(n-1, i+2)]);

	return memo[i] = min(ans, resp);
}

int main(){

	cin >> n;

	pedras.resize(n);
	for(auto &x : pedras) cin >> x;

	int dp[n]; 
	memset(dp, 0, sizeof dp);

	for(int i=1; i<n; i++)
	{
		dp[i] = min( 
			dp[max(0, i-1)] + abs(pedras[i] - pedras[max(0, i-1)]), 
			dp[max(0, i-2)] + abs(pedras[i] - pedras[max(0, i-2)]) 
		);
	}


	cout << dp[n-1] << endl;

	/********************  
	\/ solução recursiva: \/ 
	 
	memset(memo, -1, sizeof memo);
	cout << solve(0) << endl;

	********************/

	return 0;	
}
