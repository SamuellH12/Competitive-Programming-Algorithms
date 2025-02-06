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

// E. Eliminating Ballons
// https://codeforces.com/gym/103960/problem/E

int main(){

	int n; cin >> n;

	unordered_map<int, int> f;
	int ans = 0;

	for(int i=0, x; i<n; i++)
	{
		cin >> x;

		if(f[x] == 0)
		{
			f[x-1]++;
			ans++;
		}
		else
		{
			f[x]--;
			f[x-1]++;
		}

	}


	cout << ans << endl;
	
	return 0;	
}
