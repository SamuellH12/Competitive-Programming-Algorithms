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



int main(){

	int t; cin >> t;

	while(t--){
		int n, m;
		cin >> n >> m;

		map<int, int> stt, end;

		for(int i=0, l, r; i<n; i++){
			cin >> l >> r;
			stt[l]++;
			end[r]++;
		}

		cout << (stt[m] > 0 && end[m] > 0 ? "YES" : "NO") << endl;
	}
	
	return 0;	
}
