#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
using namespace std;
//https://cses.fi/problemset/task/1071

int main(){
	optimize;
	int t; cin >> t;
	ll x, y;

	while(t--)
	{
		cin >> y >> x;

		ll sqr = max(x-1, y-1) * max(x-1, y-1);

		if(max(x, y)&1LL)
		{
			if(x > y) cout << sqr + 2*x - y << endl;
			else      cout << sqr + x << endl;
		}
		else
		{
			if(x >= y) cout << sqr + y << endl;
			else       cout << sqr + 2LL*y - x << endl;
		} 
	}
	
	return 0;	
}
