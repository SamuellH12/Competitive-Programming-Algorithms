#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e3+1;
#define int ll
using namespace std;
// https://codeforces.com/contest/33/problem/D

int32_t main(){
	optimize;
	int n, m, k;
	cin >> n >> m >> k;

	vector<pii> pts(n);
	vector<bitset<MAXN>> mapa(n);

	for(auto &[x, y] : pts) cin >> x >> y;
	for(int i=0, r, x, y; i<m; i++)
	{	
		cin >> r >> x >> y;
		r *= r;

		for(int j=0; j<n; j++)
		{
			auto [a, b] = pts[j];
			if( (a-x)*(a-x) + (b-y)*(b-y) <= r ) 
				mapa[j][i] = true;
		}
	}

	int a, b;
	while(k--)
	{
		cin >> a >> b;
		a--, b--;
		cout << (mapa[a]^mapa[b]).count() << endl;
	}
	
	return 0;	
}
