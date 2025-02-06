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

///https://cses.fi/problemset/task/1750

int binlif[31][MAXN];

int main(){
	optimize;
	int n, q;
	cin >> n >> q;

	for(int i=1; i<=n; i++)
		cin >> binlif[0][i];

	for(int i=1; i<=30; i++)
		for(int j=1; j<=n; j++)
			binlif[i][j] = binlif[i-1][binlif[i-1][j]];
	
	while(q--)
	{
		int x, k;
		cin >> x >> k;

		for(int i=30; i>=0; i--)
			if(k & (1 << i))
				x = binlif[i][x];

		cout << x << endl;
	}
	
	return 0;	
}
