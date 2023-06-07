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



int main(){

	int n;
	cin >> n;
	//int a[n], b[n], c[n];
	int a, b, c;

	int dp[n+1][3];
	dp[0][0] = dp[0][1] = dp[0][2] = 0;

	for(int i=1; i<=n; i++)
	{
		cin >> a >> b >> c;
		dp[i][0] = a + max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = b + max(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = c + max(dp[i-1][0], dp[i-1][1]);
	}

	cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
	
	return 0;	
}
