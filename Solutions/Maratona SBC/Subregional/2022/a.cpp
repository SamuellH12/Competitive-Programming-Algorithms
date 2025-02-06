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

// A. Finding Maximal Non-Trivial Monotones
// https://codeforces.com/gym/103960/problem/A

int main(){

	int n, ans = 0;
	cin >> n;
	string s; cin >> s;
	s += 'b';

	int sz = 0;

	for(int i=0; i<=n; i++)
	{
		if(s[i] == 'a') sz++;
		else
		{
			if(sz > 1) ans += sz;
			sz = 0;
		}

	}
	
	cout << ans << endl;

	return 0;	
}
