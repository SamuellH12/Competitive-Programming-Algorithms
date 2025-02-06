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

// https://codeforces.com/contest/1899/problem/C

int main(){
	optimize;
	int t; cin >> t;
	while(t--){

		int n; cin >> n;

		vi sla(n);

		for(auto &x : sla) cin >> x;


		ll ans = -INF;
		ll sum = 0;
		ll mn = 0;
		for(int i=0; i<n; i++)
		{
			if(i != 0 && (sla[i]&1) == (sla[i-1]&1) ) sum = mn = 0;
			
			sum += sla[i];

			ans = max(ans, sum - mn);
			mn = min(mn, sum);
		}

		cout << ans << endl;
	}
	
	return 0;	
}
