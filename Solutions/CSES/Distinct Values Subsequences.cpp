#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://cses.fi/problemset/task/3421

const ll MOD = 1e9 + 7;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n; cin >> n;

    map<int, ll> mp;

    for(int i=1, x; i<=n && cin >> x; i++)
        mp[x]++;
    
    ll ans=1;

    for(auto [k, v] : mp)
        ans = ans*(v+1LL) % MOD;

    cout << (ans-1+MOD)%MOD << '\n';

	return 0;	
}
