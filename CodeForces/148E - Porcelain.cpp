#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
// https://codeforces.com/contest/148/problem/E

int maxSum[105][105];
int sz[105];

int dp[105][10005];

int solve(int i, int k){
	if(k == 0) return 0;
	if(i == -1) return -INF;
	if(~dp[i][k]) return dp[i][k];

	int ans = -INF;

	for(int c=0; c<=k && c<=sz[i]; c++)
		ans = max( ans, maxSum[i][c] + solve(i-1, k-c) );

	return dp[i][k] = ans;
}	

int main(){
	optimize;
	memset(dp, -1, sizeof dp);

	int n, m;
	cin >> n >> m;

	for(int i=0, s; i<n; i++)
	{
		cin >> s;
		sz[i] = s;

		vi num(s);
		for(auto &x : num) cin >> x;
		for(int j=0; j<s; j++) num.emplace_back(num[j]);

		vi ps(num.size()+1, 0);
		for(int i=0; i<num.size(); i++)
			ps[i+1] = ps[i] + num[i];


		for(int t=1; t<=s; t++)
			for(int j=s-t; j+t<=s+t; j++)
				maxSum[i][t] = max(maxSum[i][t], ps[j+t]-ps[j]);
	}


	cout << solve(n, m) << endl;
	
	return 0;	
}
