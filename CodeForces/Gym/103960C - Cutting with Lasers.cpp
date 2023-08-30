#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e3 + 5;
using namespace std;

int ho [MAXN][MAXN];
int ve [MAXN][MAXN];
bool vis[MAXN][MAXN];


ll bfs(int x, int y){

	vis[x][y] = true;
	ll ans = 1;

	queue<pii> fila;
	fila.push(pii(x, y));

	while(!fila.empty())
	{
		x = fila.front().first;
		y = fila.front().second;
		fila.pop();


		if( x > 0 && !ve[x][y] && !vis[x-1][y] ) ans++,  fila.emplace(x-1, y), vis[x-1][y] = true;
		if( y > 0 && !ho[x][y] && !vis[x][y-1] ) ans++,  fila.emplace(x, y-1), vis[x][y-1] = true;
		
		if( x+1 < MAXN && !ve[x+1][y] && !vis[x+1][y] ) ans++, fila.emplace(x+1, y), vis[x+1][y] = true;
		if( y+1 < MAXN && !ho[x][y+1] && !vis[x][y+1] ) ans++, fila.emplace(x, y+1), vis[x][y+1] = true;
	}

	return ans;
}

int main(){
	optimize;
	int n;
	cin >> n;

	int x, y;
	cin >> x >> y;

	for(int i=0, z, w; i<n; i++)
	{
		cin >> z >> w;

		if(x == z)  //vertical
		{
			if(y < w)
				ve[x][y]++,
				ve[z][w]--;
			else 
				ve[x][y]--,
				ve[z][w]++;
		}
		else	  //horizontal
		{
			if(x < z)
				ho[x][y]++,
				ho[z][w]--;
			else
				ho[x][y]--,
				ho[z][w]++;
		}

		x = z;
		y = w;
	}



	//propagar as alterações
	for(int i=1; i<MAXN ; i++)
		for(int j=1; j<MAXN; j++)
			ho[i][j] += ho[i-1][j],
			ve[i][j] += ve[i][j-1];
	

	//visitar toda a parte descartada
	bfs(MAXN-1, MAXN-1);


	ll ans = 0;
	for(int i=0; i<MAXN; i++)
		for(int j=0; j<MAXN; j++)
			if(!vis[i][j])
				ans = max(ans, bfs(i, j));


	cout << ans << endl;


	return 0;	
}
