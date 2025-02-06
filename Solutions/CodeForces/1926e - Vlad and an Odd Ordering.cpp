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
//https://codeforces.com/contest/1926/problem/E


int main(){
	optimize;
	int t; cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		int d = 1;

		while((n+1)/2 < k)
		{
			k -= (n+1)/2;
			n /= 2;
			d *= 2;
		}

		cout << d * (2*k - 1) << endl;
	}
	
	return 0;	
}
