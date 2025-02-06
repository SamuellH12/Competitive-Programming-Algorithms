#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF (int)(0x3f3f3f3f3f3f3f3f)
const int MAXN = 2e5 + 5;
using namespace std;
// https://codeforces.com/contest/1996/problem/C

int ps1[26][MAXN];
int ps2[26][MAXN];

int main(){
	optimize;
	int cs; cin >> cs;
	while(cs--){
		int n, q;
		cin >> n >> q;

		string s, t;
		cin >> s >> t;

		for(char c='a'; c<='z'; c++)
			for(int i=0; i<n; i++)
			{
				ps1[c-'a'][i+1] = ps1[c-'a'][i] + (s[i] == c);
				ps2[c-'a'][i+1] = ps2[c-'a'][i] + (t[i] == c);
			}

		int l, r;
		while(q--)
		{
			cin >> l >> r;

			int ans = 0;

			for(int c=0; c<='z'-'a'; c++)
			{
				int a1 = ps1[c][r] - ps1[c][l-1];
				int a2 = ps2[c][r] - ps2[c][l-1];
				if(a1 < a2) ans += a2 - a1;
			}

			cout << ans << endl;
		}

	}
	
	return 0;	
}
