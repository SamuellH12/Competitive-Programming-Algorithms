#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
const int MAXN = 1e5 + 5;
using namespace std;
// https://atcoder.jp/contests/abc317/tasks/abc317_d?lang=en

struct city {
	ll x, y, z;
	city(int x, int y, int z) : x(x), y(y), z(z) {}
};

int meta = 0;
vector<city> cidade;

ll memo[110][MAXN];
ll need(int i){ return max(0LL, (cidade[i].x + cidade[i].y + 1)/2 - cidade[i].x ); }

ll solve(int i, int seats){
	if(seats >= meta) return 0;
	if(i >= cidade.size()) return INF;
	if(~memo[i][seats]) return memo[i][seats];

	return memo[i][seats] = min(solve(i+1, seats), solve(i+1, seats+cidade[i].z) + need(i));
}

int main(){
	memset(memo, -1, sizeof memo);
	
	int n; cin >> n;

	for(int i=0, x, y, z; i<n; i++)
	{
		cin >> x >> y >> z;
		cidade.emplace_back(x, y, z);
		meta += z;
	}

	meta = (meta+1)/2;

	cout << solve(0, 0) << endl;
	
	return 0;	
}
