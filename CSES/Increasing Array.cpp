#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
#define vi vector<int>
using namespace std;


int main(){
	int n; cin >> n;

	ll ans = 0, mx = 0, x;

	for(int i=0; i<n; i++)
	{
		cin >> x;
		mx = max(x, mx);
		ans += mx - x;
	}
	
	cout << ans << endl;

	return 0;	
}