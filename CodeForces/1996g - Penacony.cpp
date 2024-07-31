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
// https://codeforces.com/contest/1996/problem/G

#define int ll

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


int32_t main(){
	optimize;
	int t; cin >> t;
	while(t--){

		int n, m; cin >> n >> m;

		vi hsh(n);

		while(m--)
		{
			int a, b, v = rng();
			cin >> a >> b;

			hsh[--a] ^= v;
			hsh[--b] ^= v;
		}

		map<int, int> cnt;
		cnt[hsh[0]]++;
		int mx = 1;
		
		for(int i=1; i<n; i++)
			mx = max(mx, ++cnt[hsh[i] ^= hsh[i-1]]);

		cout << n - mx << endl;
	}
	
	return 0;	
}
