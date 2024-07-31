#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF (int)(0x3f3f3f3f3f3f3f3f)
const int MAXN = 1e3 + 5;
using namespace std;
// https://codeforces.com/contest/1996/problem/B


#define int ll

char grid[MAXN][MAXN];
char red[MAXN][MAXN];

int32_t main(){
	optimize;
	int t; cin >> t;
	while(t--){

		int n, k;
		cin >> n >> k;

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++)
			{	
				cin >> grid[i][j];
				red[i/k][j/k] = grid[i][j];
			}
		}

		for(int i=0; i<n/k; i++){
			for(int j=0; j<n/k; j++)
				cout << red[i][j];
			cout << endl;
		}
	}
	
	return 0;	
}
