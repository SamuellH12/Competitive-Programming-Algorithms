#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
using namespace std;
//https://cses.fi/problemset/task/1617

const ll MOD = 1e9 + 7;

int main(){

	ll p; cin >> p;

	ll ans = 1, b=2;
	
	while(p)
	{	
		if(p&1) ans = ans * b % MOD;
		b = b*b % MOD;
		p >>= 1;
	}

	cout << ans << endl;

	return 0;	
}
