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
//https://olimpiada.ic.unicamp.br/pratique/p2/2019/f1/chuva/

int n, m;
vector<string> mapa;

void dfs(int y, int x)
{
	mapa[y][x] = 'o';
	

	if( y+1 < n && mapa[y+1][x] == '.')
	{
		dfs(y+1, x);
	}
	else
	if( y+1 < n && mapa[y+1][x] == '#')
	{
		if( x > 0   && mapa[y][x-1] != 'o') dfs(y, x-1);
		if( x+1 < m && mapa[y][x+1] != 'o') dfs(y, x+1); 
	}

}

int main(){
	cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		string x;
		cin >> x;
		mapa.push_back(x);
	}

	int g;
	for(int i=0; i<m; i++)
		if(mapa[0][i] == 'o')
		{ g = i; break; }
	
	
	dfs(0, g);
	debug;
	for(int i=0; i<n; i++)
	{
		for(int e=0; e<m; e++)
			cout << mapa[i][e];
		cout<<endl;
	}

	return 0;	
}
