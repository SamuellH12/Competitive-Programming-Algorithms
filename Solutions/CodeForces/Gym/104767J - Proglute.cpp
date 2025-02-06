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
// https://codeforces.com/gym/104767/problem/J

#define int ll

const int MOD = 1e9 + 7;

int32_t main(){

	int n; cin >> n;

	if(n == 2)
	{
		cout << 1 << endl;
		return 0;
	}

	int ans = 1;

	for(int i=0; i<n-3; i++)
		ans = (ans*2) % MOD;

	cout << (ans*n) % MOD << endl;

	return 0;	
}
