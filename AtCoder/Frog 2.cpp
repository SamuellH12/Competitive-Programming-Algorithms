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

int main(){
	int n, k; 
	cin >> n >> k;

	vi pedras(n);
	for(auto &x : pedras) cin >> x;

	int dp[n]; 
	memset(dp, 0, sizeof dp);

	for(int i=1; i<n; i++)
	{
		dp[i] = INF;
		for(int j=1; j<=k && j <= i; j++)
			dp[i] = min(dp[i], dp[i-j] + abs(pedras[i] - pedras[i-j]));
	}


	cout << dp[n-1] << endl;

	return 0;	
}
