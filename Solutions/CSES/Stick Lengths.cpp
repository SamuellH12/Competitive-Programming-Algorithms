#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://cses.fi/problemset/task/1074

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n; cin >> n;
	
	vector<int> sla(n);
	for(auto &x : sla) cin >> x;

	sort(begin(sla), end(sla));

	ll m = sla[n/2], ans=0;

	for(auto &x : sla) ans += abs(x - m);

	cout << ans << endl;

	return 0;	
}
