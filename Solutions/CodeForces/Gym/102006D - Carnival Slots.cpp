#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<long long>
#define pii pair<int,int>
#define MAXN 510
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok"
using namespace std;
//https://codeforces.com/gym/102006/problem/D

vector<string> grid;
vi balde;
vi ball;
int l, c;
ll dp[MAXN][MAXN];

ll solve(int p, int h)
{
	if(p < 0 || p >= c) return 0;
	if(h == l) return balde[p];
	if(dp[p][h] != -1) return dp[p][h];

	ll resp = 0;

	if(grid[h][p] == '.')
	{
		resp = solve(p, h+1);
	}
	else
	{
		resp = max(resp, solve(p, h+1) );
		resp = max(resp, solve(p + 1, h+1) );
		resp = max(resp, solve(p - 1, h+1) );
	}

	return dp[p][h] = resp;
}

int main(){
	optimize;

	freopen("balls.in", "r", stdin);

	int casos; cin>>casos;
	
	while(casos--)
	{
		for(int i=0; i<MAXN; i++)
			for(int j=0; j<MAXN; j++)
				dp[i][j] = -1;

		cin>>l>>c;

		grid = vector<string> (l);

		for(int i=0, b; i<c; i++)
		{
			cin>>b;
			ball.push_back(b);
		}

		for(int i=0; i < l; i++)
			cin>>grid[i];

		for(int i=0, b; i<c; i++)
		{
			cin>>b;
			balde.push_back(b);
		}

		ll resp = 0;

		for(int i=0; i<c; i++)
		{
			resp += ball[i] * solve(i, 0);
		}

		cout<<resp<<endl;

		ball.clear();
		balde.clear();
		grid.clear();
	}


	return 0;	
}
