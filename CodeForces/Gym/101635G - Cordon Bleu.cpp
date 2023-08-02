#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll int
#define vi vector<int>
#define pii pair<ll,ll>
using namespace std;



typedef int TP;

const int MAXN = 2*1e3 + 5;
const TP INF = 0x3f3f3f3f;

TP matrix[MAXN][MAXN];
TP row[MAXN], col[MAXN];
int match[MAXN], way[MAXN];

TP hungarian(int n, int m){
	memset(row, 0, sizeof row);
	memset(col, 0, sizeof col);
	memset(match, 0, sizeof match);

	for(int i=1; i<=n; i++)
	{
		match[0] = i;
		int j0 = 0, j1, i0;
		TP delta;

		vector<TP> minv (m+1, INF);
		vector<bool> used (m+1, false);

		do {
			used[j0] = true;
			i0 = match[j0];
			j1 = -1;
			delta = INF;

			for(int j=1; j<=m; j++)
				if(!used[j]){
					TP cur = matrix[i0][j] - row[i0] - col[j];

					if( cur < minv[j] ) minv[j] = cur, way[j] = j0;
					if(minv[j] < delta) delta = minv[j], j1 = j;
				}

			for(int j=0; j<=m; j++)
				if(used[j]){
					row[match[j]] += delta,
					col[j] -= delta;
				}else 
					minv[j] -= delta;

			j0 = j1;
		} while(match[j0]);
		

		while(j0){
			j1 = way[j0];
			match[j0] = match[j1];
			j0 = j1;
		} 
	}

	return -col[0];
}


vector<pair<int, int>> getAssignment(int m){
	vector<pair<int, int>> ans;

	for(int i=1; i<=m; i++)
		ans.push_back(make_pair(match[i], i));

	return ans;
}


int32_t main(){

	int n, m;
	cin >> n >> m;

	vector<pii> bot(n);
	vector<pii> cor(m);

	for(pii &x : bot) cin >> x.first >> x.second;
	for(pii &x : cor) cin >> x.first >> x.second;

	ll x, y;
	cin >> x >> y;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			matrix[i][j] = abs(bot[i-1].first - cor[j-1].first) +  abs(bot[i-1].second - cor[j-1].second) + (abs(bot[i-1].first - x) +  abs(bot[i-1].second - y));


	for(int i=1; i<=n; i++)
		for(int j=m+1; j<m+n; j++)
			matrix[i][j] = 2*(abs(bot[i-1].first - x) +  abs(bot[i-1].second - y));


	ll ans = hungarian(n, m+n-1);

	cout << ans << endl;
	
	return 0;	
}
