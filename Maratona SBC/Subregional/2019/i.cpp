#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 1000000
const int MAXN = 405;
using namespace std;

// I. Interplanetary
// https://codeforces.com/gym/102346/problem/I


int dist[2][MAXN][MAXN];
int mapa[2][MAXN][MAXN][MAXN];
int n, r;

int main(){
	optimize;
	cin >> n >> r;

	for(int i=0; i<MAXN; i++)
		for(int j=0; j<MAXN; j++)
			dist[0][i][j] = dist[1][i][j] = INF;
		

	map<int, int> rnk;
	vector<pii> temp;


	for(int i=1, t; i<=n; i++)
	{
		cin >> t;
		temp.emplace_back(t, i);
		rnk[t] = INF;
	}


	int cnt = 1;
	for(auto &x : rnk) x.second = cnt++;
	
	
	for(int i=0, u, v, d; i<r; i++)
	{
		cin >> u >> v >> d;
		dist[0][u][v] = dist[0][v][u] = d;
		dist[1][u][v] = dist[1][v][u] = d;
	}


	sort(ALL(temp));

	//FLOYD WARSHAL ORDENADO PELA TEMPERATURA:

	//COLD
	for(auto [t, k] : temp)
	{
		int c = rnk[t];

		for(int i=1; i<=n; i++) 
			for(int j=1; j<=n; j++)
				mapa[0][c][i][j] = dist[0][i][j] = min(dist[0][i][j], dist[0][i][k] + dist[0][k][j]);
	}


	reverse(ALL(temp));

	//HOT
	for(auto [t, k] : temp)
	{
		int c = cnt - rnk[t];

		for(int i=1; i<=n; i++) 
			for(int j=1; j<=n; j++)
				mapa[1][c][i][j] = dist[1][i][j] = min(dist[1][i][j], dist[1][i][k] + dist[1][k][j]);
	}


	int q, u, v, k, t;  cin >> q;

	while(q--)
	{
		cin >> u >> v >> k >> t;

		k = min(k, cnt-1);
		assert(k < cnt);

		cout << ( mapa[t][k][u][v] != INF ? mapa[t][k][u][v] : -1 ) << endl;
	}
	
	return 0;	
}