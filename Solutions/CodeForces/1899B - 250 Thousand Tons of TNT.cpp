#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;

#define int long long

// https://codeforces.com/contest/1899/problem/B

int32_t main(){
	optimize;
	int t; cin >> t;
	while(t--){

		int n; cin >> n;

		vi sla(n);

		for(auto &x : sla) cin >> x;

		vi div (1, 1);

		for(int i=2; i*i <= n; i++)
			if(n%i == 0) div.push_back(i), div.push_back(n/i);
		
		int ans = 0;

		for(auto sz : div)
		{
			int mx = -1, mn = INF;

			for(int i=0; i<n/sz; i++)
			{
				int sum = 0;

				for(int j=0; j<sz; j++)
					sum += sla[sz*i + j];

				mx = max(mx, sum);
				mn = min(mn, sum);
			}

			//cerr << sz << " mn" << mn << " mx" << mx << endl;
			ans = max(ans, abs(mx - mn));
		}

		///cerr << "ans = " << ans << endl;	

		cout << ans << endl;
	}
	
	return 0;	
}
