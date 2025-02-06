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

// https://codeforces.com/contest/1899/problem/E

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;

		int imn = 0;

		vi sla(n);

		for(int i=0; i<n; i++)
		{
			cin >> sla[i];

			if(sla[i] < sla[imn]) imn = i;
		}


		bool ok = true;

		for(int i=imn+1; i<n; i++)
			if(sla[i-1] > sla[i]) 
				ok = false;

		cout << (ok ? imn : -1) << endl;
	}
	
	return 0;	
}
