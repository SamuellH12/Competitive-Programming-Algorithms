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

// H. Hour for a Run
// https://codeforces.com/gym/102346/problem/H


int main(){
	ll l, s;
	cin >> l >> s;

	ll tot = l*s;

	for(ll i=1; i<10; i++) 
		cout << (i * tot + 9) / 10 << " ";

	cout << endl;
	
	return 0;	
}
