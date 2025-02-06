#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<long long>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;

// https://cses.fi/problemset/task/1646

//Tem que usar ll

int main(){

	int n, q; cin >> n >> q;
	vi ps (n+1, 0);

	for(int i=1; i<=n; i++){
		cin >> ps[i];
		ps[i] += ps[i-1];
	}
	

	int a, b;

	while(q--){
		cin >> a >> b;
		cout << ps[b] - ps[a-1] << endl;
	}


	
	return 0;	
}
