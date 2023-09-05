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

// M. Maratona Brasileira de Popcorn
// https://codeforces.com/gym/102346/problem/m

int n, c, t;
vi pip;

int check(int lim){

	int tot = 1, at = 0;
	for(auto p : pip)
	{
		if((at+p + (t-1))/t <= lim) at += p;
		else if((p + (t-1))/t <= lim) tot++, at = p;
		else
			return INF;
	}

	cerr << lim << " " << tot << endl;

	return tot;
}

int main(){
	cin >> n >> c >> t;
	pip.resize(n);

	for(auto &x : pip) cin >> x;

	int l=1, r = INF, m, ans = 0;

	while(l <= r)
	{
		m = (l+r)/2;

		if(check(m) <= c)
		{
			ans = m;
			r = m-1;
		}
		else
		{
			l = m+1;
		}
	}

	cout << ans << endl;
	
	return 0;	
}
