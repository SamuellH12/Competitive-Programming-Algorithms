#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 2e5 + 5;
using namespace std;
//https://codeforces.com/contest/1926/problem/C

int memo[MAXN];

int main(){
	memo[0] = 0;
	
	for(int i=1, n; i<MAXN; i++)
	{
		memo[i] = memo[i-1];
		n = i;
		while(n) memo[i] += n%10, n/=10;
	}

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << memo[n] << endl;
	}
	
	return 0;	
}
