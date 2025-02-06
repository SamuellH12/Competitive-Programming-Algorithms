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
//https://codeforces.com/contest/1926/problem/F

const int n = 7;

bool mat[n][n];
int cnt[n][n];
vector<pii> dir = {pii(0, 0), pii(1, 1), pii(1, -1), pii(-1, 1), pii(-1, -1)};

inline bool valido(int i, int j){ return 0 <= i && i < n && 0 <= j && j < n; }

bool testa(int i, int j, int v=1)
{
	for(auto [x, y] : dir)
		if(!valido(i+x, j+y) || !mat[i+x][j+y]) 
			return false;

	return true;
}
bool paridade = true;

bool funciona(){
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if((i+j)%2 == paridade && testa(i, j))
				return false;
	
	return true;
}

bool solve(int i, int j, int d)
{	
	if(j == n) i++, j=0;
	if(i >= n) return false;
	if(d == 0) return funciona();
	if((i+j)%2 != paridade) return solve(i, j+1, d);

	// cerr << i << " " << j << endl;

	if(solve(i, j+1, d)) return true;

	if(mat[i][j])
	{
		mat[i][j] = 0;
		if(solve(i, j+1, d-1)) return true;
		mat[i][j] = 1;
	}

	return false;
}

int main(){
	optimize;
	int t; cin >> t;
	while(t--){
		memset(cnt, 0, sizeof cnt);
		char c;

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin >> c,
				mat[i][j] = (c == 'B');

		int ans = 0;

		paridade = true;
		for(int i=0; i<5; i++)
			if(solve(0, 0, i))
			{
				ans += i;
				break;
			}
		
		// cerr << "ok ok" << endl;
		
		paridade = false;
		for(int i=0; i<5; i++)
			if(solve(0, 0, i))
			{
				ans += i; 
				break;
			}

		cout << ans << endl;
	}
	
	return 0;	
}
