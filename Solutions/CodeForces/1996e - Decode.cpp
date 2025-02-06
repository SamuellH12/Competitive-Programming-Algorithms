#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF (int)(0x3f3f3f3f3f3f3f3f)
const int MAXN = 1e6 + 5;
using namespace std;
// https://codeforces.com/contest/1996/problem/E

#define int ll
const int MOD = 1e9 + 7;

int32_t main(){
	optimize;
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		int n = s.size();

		map<int, int> sla;
		sla[0] = 1;

		int sum = 0;
		int ans = 0;
		int id = 1;
		for(auto c : s)
		{
			sum += c == '0' ? -1LL : 1LL;
			ans += (sla[sum] * (n-id+1LL)) % MOD;
			ans %= MOD;
			sla[sum] += ++id;
		}

		cout << ans << endl;
	}
	
	return 0;	
}
