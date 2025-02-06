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
//https://codeforces.com/contest/1926/problem/D


int main(){
	optimize;
	int t; cin >> t;
	while(t--){
		int n;
		cin >> n;

		vi sla(n);
		int ans = 0;

		multiset<int> s;

		for(auto &x : sla){
			cin >> x;

			auto it = s.find((~x)^(1<<31));
			
			if(it != s.end()) s.erase(it);
			else ans++, s.insert(x);
		}

		cout << ans << endl;
	}
	
	return 0;	
}
