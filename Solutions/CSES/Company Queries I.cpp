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
//https://cses.fi/problemset/task/1687/

int bl[32][MAXN];

int main(){
	optimize;
	int n, q;

	cin >> n >> q;
	
	memset(bl, -1, sizeof bl);

	for(int i=2; i<=n; i++)
		cin >> bl[0][i];
	
	for(int i=1; i<=30; i++)
		for(int j=2; j<=n; j++)
		{
			if(bl[i-1][j] == -1) continue;
			bl[i][j] = bl[i-1][bl[i-1][j]];
		}

	
	int x, k;
	while(q--)
	{
		cin >> x >> k;

		for(int i=30; i>=0 && x != -1; i--)
			if(k & (1 << i))
				x = bl[i][x];

		cout << x << endl;
	}
	
	return 0;	
}
