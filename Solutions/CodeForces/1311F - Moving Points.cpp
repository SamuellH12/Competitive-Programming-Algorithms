#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<ll,ll>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
//https://codeforces.com/contest/1311/problem/F

ll bit[MAXN];
ll cnt[MAXN];
void update(int pos, ll v){
	for(; pos < MAXN; pos += pos&(-pos))
		bit[pos] += v;
}
ll query(int pos){
	ll sum = 0;
	for(; pos > 0; pos -= pos&(-pos))
		sum += bit[pos];
	return sum;
}
void updatecnt(int pos, ll v){
	for(; pos < MAXN; pos += pos&(-pos))
		cnt[pos] += v;
}
ll querycnt(int pos){
	ll sum = 0;
	for(; pos > 0; pos -= pos&(-pos))
		sum += cnt[pos];
	return sum;
}

int main(){

	int n; cin >> n;

	vector<pii> sla(n);
	vi cd;

	for(auto &[v, x] : sla) cin >> x, cd.emplace_back(x);
	for(auto &[v, x] : sla) cin >> v;

	sort(ALL(sla));
	sort(ALL(cd));
	cd.resize(unique(ALL(cd)) - cd.begin());

	auto getPos = [&](int x){ return lower_bound(ALL(cd), x) - cd.begin() + 1; };

	ll ans = 0;

	for(auto [v, x] : sla)
	{
		int pos = getPos(x);
		ans += x*querycnt(pos) - query(pos);
		updatecnt(pos, 1);
		update(pos, x);
	}

	cout << ans << endl;

	return 0;	
}
