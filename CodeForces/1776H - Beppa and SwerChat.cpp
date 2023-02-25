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

//https://codeforces.com/contest/1776/problem/H

int main(){
	int t; cin >>t;

	while(t--)
	{
		int n; cin >> n;

		int resp=0, a[n], b[n];

		for(int i=0; i<n; i++)
			cin >> a[i];
		for(int i=0; i<n; i++)
			cin >> b[i];

		for(int i=n-1, j=n-1; j>=0; j--)
			if( b[i] == a[j] ) resp++, i--;
		

		cout << n - resp << endl;
	}
	
	
	return 0;	
}
