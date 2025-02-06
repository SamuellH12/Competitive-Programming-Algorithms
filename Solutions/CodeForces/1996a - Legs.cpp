#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF (int)(0x3f3f3f3f3f3f3f3f)
const int MAXN = 1e6 + 5;
using namespace std;
// https://codeforces.com/contest/1996/problem/A

#define int ll

int32_t main(){
	optimize;
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << (n/4 + (n%4)/2) << endl;
	}
	
	return 0;	
}
