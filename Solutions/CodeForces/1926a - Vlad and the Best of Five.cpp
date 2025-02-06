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
//https://codeforces.com/contest/1926/problem/A
int occ[2];

int main(){
	optimize;
	int t; cin >> t;
	while(t--){

		occ[0] = occ[1] = 0;
		string s; cin >> s;

		for(auto c : s) occ[c - 'A']++;

		cout << (occ[0] > occ[1] ? "A" : "B") << endl;
	}
	
	return 0;	
}
