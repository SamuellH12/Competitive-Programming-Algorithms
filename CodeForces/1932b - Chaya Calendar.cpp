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
// https://codeforces.com/contest/1932/problem/B

#define int ll

int32_t main(){
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;

		vi sla(n);

		for(auto &x : sla) cin >> x;

		ll ano = 0;

		for(auto &x : sla)
		{

			int l=0, r = 1e9, ans = -1, mid;
			while(l <= r)
			{
				mid = (l+r) / 2;
				if(x*mid > ano)
				{
					ans = mid;
					r = mid-1;
				}
				else
					l = mid+1;
			}

			ano = x*ans;
		}

		cout << ano << endl;
	}
	
	return 0;	
}
