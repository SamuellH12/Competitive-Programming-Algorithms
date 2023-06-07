#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e5 + 5;
using namespace std;

//https://atcoder.jp/contests/dp/tasks/dp_e?lang=en

vector<pii> nap;
int memo[110][MAXN];
int n, w;

int solve(int i, int v)
{
	if(v == 0) return 0;
	if(v < 0) return INF;
	if(i >= n) return INF;
	if(memo[i][v] != -1) return memo[i][v];

	int ans = solve(i+1, v);
	int resp= solve(i+1, v-nap[i].second) + nap[i].first;

	return memo[i][v] = min(ans, resp);
}


int main(){
	memset(memo, -1, sizeof memo);
	cin >> n >> w;

	nap.resize(n);
	int tot = 0;
	for(auto &x : nap){
		cin >> x.first >> x.second;
		tot += x.second;
	} 
		
	int resp = 0;
	for(int i=tot; i>=0; i--){
		if(solve(0, i) <= w)
		{
			resp = i;
			break;
		}
	}

	cout << resp << endl;

	return 0;	
}
