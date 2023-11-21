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

// https://codeforces.com/contest/1899/problem/F

int main(){
	int t; cin >> t;
	while(t--){

		int n, q;
		cin >> n >> q;

		for(int i=1; i<n; i++) cout << i << " " << i+1 << endl;

		int at = n-1;

		int d;
		while(q--)
		{
			cin >> d;

			if(d == at) cout << -1 << " " << -1 << " " << -1 << endl;
			else cout << n << " " << at << " " << (at = d) << endl;
		}
		
	}
	
	return 0;	
}
