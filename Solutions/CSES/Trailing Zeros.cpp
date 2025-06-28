#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
using namespace std;
//https://cses.fi/problemset/task/1617

const ll MOD = 1e9 + 7;

int main(){

	ll n; cin >> n;

	ll fives = 0;

	for(ll at=5; at <= n; at *= 5)
		fives += n / at;

	cout << fives << endl;

	return 0;	
}
