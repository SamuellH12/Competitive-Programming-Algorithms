#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
using namespace std;

//https://cses.fi/problemset/task/2129/

const int MAXN = 1e3 + 5;
const int INF = 0x3f3f3f3f;

int matrix[MAXN][MAXN];
int row[MAXN], col[MAXN], match[MAXN], way[MAXN];

int hungarian(int n, int m){
	memset(row, 0, sizeof row);
	memset(col, 0, sizeof col);
	memset(match, 0, sizeof match);

	for(int i=1; i<=n; i++)
	{
		match[0] = i;
		int j0 = 0, j1, i0, delta;

		vector<int> minv (m+1, INF);
		vector<bool> used (m+1, false);

		do {
			used[j0] = true;
			i0 = match[j0];
			j1 = -1;
			delta = INF;

			for(int j=1; j<=m; j++)
				if(!used[j]){
					int cur = matrix[i0][j] - row[i0] - col[j];

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
		

		do {
			j1 = way[j0];
			match[j0] = match[j1];
			j0 = j1;
		} while(j0);
	}

	return -col[0];
}


vector<pair<int, int>> getAssignment(int m){
	vector<pair<int, int>> ans;

	for(int i=1; i<=m; i++)
		ans.push_back(make_pair(match[i], i));

	return ans;
}



int main(){
	int n; cin >> n;

	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin >> matrix[i][j];

	cout << hungarian(n, n) << endl;
	
	auto assig = getAssignment(n);

	for(auto [a, b] : assig)
		cout << a << " " << b << endl;
	
	return 0;	
}
