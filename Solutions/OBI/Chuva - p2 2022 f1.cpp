//Samuell H C P C - OBI 2022 - IFPI
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

	int n, s; cin>>n>>s;

	vi pre(n+1); pre[0] = 0;

	for(int i=1, x; i <= n; i++)
	{
		cin >> x;
		pre[i] = pre[i-1] + x;
	}

	ll resp = 0;

	for(int i=1; i <= n; i++)
	{
		resp += upper_bound( pre.begin() + i, pre.end(), abs(pre[i-1] + s) )
			  - lower_bound( pre.begin() + i, pre.end(), abs(pre[i-1] + s) );
	}

	cout << resp << endl;	

	
	return 0;	
}
