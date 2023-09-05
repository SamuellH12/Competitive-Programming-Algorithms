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

// E. Escalator
// https://codeforces.com/gym/103388/problem/E


#define int long long

int32_t main(){

	int n; cin >> n;

	vector<pii> p(n);

	for(auto &x : p) cin >> x.first >>x.second;
	
	int nxtstp = -1, dir = 3;
	int wait = -1; 

	for(int i=0; i<n; i++)
	{
		if(wait != -1 && p[i].first >= nxtstp)
		{	
			dir = !dir;
			nxtstp = nxtstp + 10;
			wait = -1;
		}	
		
		
		if(p[i].first >= nxtstp)
		{
			dir = p[i].second;
			nxtstp = p[i].first + 10;
		}
		else
		if(p[i].second == dir)
		{
			nxtstp = p[i].first + 10;
		}
		else
		{
			wait = p[i].first;
		}

	}

	if(wait != -1)
	{	
		dir = !dir;
		nxtstp = nxtstp + 10;
		wait = -1;
	}

	cout << nxtstp << endl;
	
	return 0;	
}
