#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://cses.fi/problemset/task/1643

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n; cin >> n;
	
	ll ans = -1e18, mn=0, sum=0;

	for(int i=0, x; i<n; i++)
	{
		cin >> x;
		sum += x;
		ans = max(ans, sum-mn);
		mn = min(mn, sum);
	}

	cout << ans << '\n';

	return 0;	
}
