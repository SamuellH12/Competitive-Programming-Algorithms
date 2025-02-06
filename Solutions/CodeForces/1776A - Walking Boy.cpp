#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;

//https://codeforces.com/contest/1776/problem/A

int main(){
	int t; cin >> t;

	while(t--){

		int  n, c=0, h, a=0;
		cin >> n;

		while(n--)
		{
			cin >> h;
			c += (h-a) /120;
			a = h;
		}

		c += (1440 - a) / 120;

		cout << (c >= 2 ? "YES" : "NO") << endl;
	}
	
	
	return 0;	
}
