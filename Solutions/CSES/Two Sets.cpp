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
// https://cses.fi/problemset/task/1617


int main(){

	ll n; cin >> n;

	if((n*(n+1LL)/2LL) % 2LL){
		cout << "NO" << endl;
		return 0;
	}

	ll sum = (n*(n+1LL)/2LL) / 2LL;

	set<int> sla;
	for(int i=n; i; i--)
		if(i <= sum)
			sum -= i,
			sla.emplace(i);

	cout << "YES" << endl;

	cout << sla.size() << endl;
	for(auto x : sla) cout << x << " ";
	cout << endl;
	
	cout << n - sla.size() << endl;
	for(int i=1; i<=n; i++)
		if(!sla.count(i))
			cout << i << " ";
	cout << endl;
	
	return 0;	
}
