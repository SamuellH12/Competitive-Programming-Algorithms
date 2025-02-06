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
	optimize;
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vi A, B, C, D;

		for(int i=0, a, b, c, d; i<n; i++){
			cin >> a >> b >> c >> d;
			A.push_back(a);
			B.push_back(b);
			C.push_back(c);
			D.push_back(d);
		}

		ll resp = 0;
		unordered_map<ll, int> mp;

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				mp[A[i] + B[j]]++;

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				resp += mp[-(C[i] + D[j])];

		cout << resp << endl;
		if(t > 0) cout << endl;
	}
	
	
	return 0;	
}
