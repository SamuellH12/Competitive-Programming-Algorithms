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
// https://codeforces.com/contest/1996/problem/D

#define int ll


int32_t main(){
	optimize;
	int t; cin >> t;
	while(t--){
		int n, x;
		cin >> n >> x;

		int ans = 0;

		for(int a=1; a<=n; a++)
			for(int b=a; b<=n && a*b < n && a + b < x; b++)
				for(int c=b; c<=n && a*b + b*c + a*c <= n && a+b+c <= x; c++)
					if(a == b && b == c) ans += 1; // 3! / 3!   todos iguais
					else 
					if(a != b && b != c) ans += 6; // 3! 	    todos diferentes
					else 
					if(true)             ans += 3;  // 3! / 2!	dois iguais

		cout << ans << endl;
	}
	
	return 0;	
}
