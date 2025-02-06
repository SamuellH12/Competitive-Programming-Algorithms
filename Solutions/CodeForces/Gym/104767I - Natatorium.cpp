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
// https://codeforces.com/gym/104767/problem/I

#define int ll

int32_t main(){

	int c; cin >> c;

	int n; cin >> n;

	int ans, resp;
	set<int> sla;

	for(int i=0, x; i<n; i++)
	{
		cin >> x;
		if(c%x == 0 && sla.count(c/x)) ans = x, resp = c/x;
		sla.insert(x);
	}
	

	cout << min(ans, resp) << " " << max(ans, resp) << endl;
	
	return 0;	
}
