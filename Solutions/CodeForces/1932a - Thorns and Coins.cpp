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
// https://codeforces.com/contest/1932/problem/A


int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;

		bool ok = true;
		int ans = 0;
		for(int i=1; i<n; i++)
		{
			if(s[i] == '@') ans++;
			if(s[i] == '*' && s[i-1] == '*') break;
		}

		cout << ans << endl;
	}
	
	return 0;	
}
