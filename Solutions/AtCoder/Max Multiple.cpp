#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<ll>
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;

//https://atcoder.jp/contests/abc281/tasks/abc281_d?lang=en

ll memo[105][105][105];
int n, c, d;
vi num;

ll solve(int i, int k, ll md){
	if(k == 0) return (md == 0 ? 0 : -INF);
	if(i == n) return -INF;
	if(memo[i][k][md] != -1) return memo[i][k][md];

	ll ans = -1;

	//get
	ans = solve(i+1, k-1, (md+num[i])%d) + num[i];

	//dont get
	ans = max(ans, solve(i+1, k, md));

	return memo[i][k][md%d] = ans;
}

int main(){
	memset(memo, -1, sizeof memo);
	cin >> n >> c >> d;

	num.resize(n);
	for(auto &x : num) cin >> x;

	sort(ALL(num));
	reverse(ALL(num));

	ll ans = solve(0, c, 0);

	cout << max(ans, -1ll) << endl;
	
	return 0;	
}
