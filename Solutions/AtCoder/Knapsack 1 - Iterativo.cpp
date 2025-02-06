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

	int n, w;
	cin >> n >> w;

	vector<pii> nap(n);

	for(auto &x : nap) cin >> x.first >> x.second;

	ll dp[n+2][w+2];
	memset(dp, 0, sizeof dp);


	for(int i=0; i<n; i++){
		for(int j=1; j<=w; j++)
		{

			if( j >= nap[i].first )
			{
				dp[i+1][j] = max( 
					dp[i][ j - nap[i].first ] + nap[i].second,
					dp[i][j]
				);
			}
			else
				dp[i+1][j] = dp[i][j];

			
		}

	}

	
	cout << dp[n][w] << endl;

	return 0;	
}
