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
//https://olimpiada.ic.unicamp.br/pratique/p2/2018/f2/fuga/

int n, m, resp = 0;
int ex, ey, sx, sy;
bool vis [12][12];

void dfs(int x, int y, int c)
{
	if(x > n || y > m || x == 0 || y == 0) return;
	if( x%2 == 0 && y%2 == 0 ) return;
	if(vis[x][y]) return;

	c++;
	vis[x][y] = true;

	if( x == sx && y == sy ) resp = max(resp, c);
	else
	{
		dfs(x+1, y, c);
		dfs(x-1, y, c);
		dfs(x, y+1, c);
		dfs(x, y-1, c);
	}
	vis[x][y] = false;
}

int main(){
	cin >> n >> m >> ex >> ey >> sx >> sy;

	dfs(ex, ey, 0);
	
	cout << resp << endl;
	
	return 0;	
}
