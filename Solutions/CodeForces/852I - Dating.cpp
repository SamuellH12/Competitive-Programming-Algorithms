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
// https://codeforces.com/contest/852/problem/I

const int BLOCK_SZ = 500;

struct Query{
	int l, r, idx;

	Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
	
	bool operator < (Query q) const {
		if(l / BLOCK_SZ != q.l / BLOCK_SZ) return l < q.l;
		return (l / BLOCK_SZ &1) ? ( r < q.r ) : (r > q.r );
	}
};

vector<int> g[MAXN];
int gender[MAXN];
int num[MAXN];

int tin[MAXN], tout[MAXN];
int pai[MAXN], idg[MAXN];
vector<int> order;
int TIME = 0;

void dfs(int u, int p=0){
	tin[u] = TIME++;
	pai[u] = p;
	order.emplace_back(u);

	for(auto v : g[u])
		if(tin[v] == -1)
			dfs(v, u);

	tout[u] = TIME-1;
}

ll ANS = 0;
ll mp[2][MAXN];

void remove(int u){
	ANS -= mp[!gender[u]][num[u]];
	mp[gender[u]][num[u]]--;
}
void add(int u){
	ANS += mp[!gender[u]][num[u]];
	mp[gender[u]][num[u]]++;
}

void go_to(int ti, int tp, int otp){
	int u = order[ti], v;
	int to = tout[u];
	
	while(!(ti <= tp && tp <= to)){
		v = pai[u];

		if(ti <= otp && otp <= to) add(v);
		else remove(u);

		u = pai[u];
		ti = tin[u];
		to = tout[u];
	}

	while(ti < tp){
		int &i = idg[u];

		while(tout[g[u][i]] < tp) i++;
		while(tin [g[u][i]] > tp) i--;
		
		v = g[u][i];
		ti = tin [v];
		to = tout[v];

		if(ti <= otp && otp <= to) remove(u);
		else add(v);
		
		u = g[u][i];
	}
}

vector<ll> MO(vector<Query> &queries){
	vector<ll> ans(queries.size());

	sort(queries.begin(), queries.end());

	int L = 0, R = 0;
	add(0);

	for(auto [l, r, idx] : queries)
	{
		if(l < L) go_to(L, l, R), L = l;
		if(r > R) go_to(R, r, L), R = r;
		if(l > L) go_to(L, l, R), L = l;
		if(r < R) go_to(R, r, L), R = r;

		ans[idx] = ANS;
	}

	return ans;
}

int main(){
	optimize;
	memset(tin,  -1, sizeof tin);
	int n; cin >> n;

	for(int i=0; i<n; i++) cin >> gender[i];
	vector<int> cord;
	for(int i=0; i<n; i++) cin >> num[i], cord.emplace_back(num[i]);

	sort(ALL(cord));
	cord.resize(unique(ALL(cord)) - begin(cord));
	for(int i=0; i<n; i++) 
		num[i] = lower_bound(ALL(cord), num[i]) - begin(cord);

	for(int i=1, u, v; i<n && cin >> u >> v; i++){
		u--, v--;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}

	dfs(0);

	for(int i=1; i<n; i++){
		for(int j=0; j+1<g[i].size(); j++)
			if(g[i][j] == pai[i])
				swap(g[i][j], g[i][j+1]);
		g[i].pop_back();
	}

	vector<Query> queries;
	
	int q; cin >> q;
	for(int i=0, u, v; i<q; i++)
	{
		cin >> u >> v;
		u--, v--;
		if(tin[u] > tin[v]) swap(u, v);
		queries.emplace_back(tin[u], tin[v], i);
	}

	auto ans = MO(queries);
	for(auto &x : ans) cout << x << endl;

	return 0;	
}

/*
// if hilbert
// vector<ll> h(ans.size());
// for (int i = 0; i < ans.size(); i++) h[i] = hilbert(queries[i].l, queries[i].r);
// sort(queries.begin(), queries.end(), [&](Query&a, Query&b) { return h[a.idx] < h[b.idx]; });

inline ll hilbert(int x, int y) {
	static int N = 1 << (__builtin_clz(0) - __builtin_clz(MAXN));
	int rx, ry, s;
	ll d = 0;
	for (s = N/2; s > 0; s /= 2) {
		rx = (x & s) > 0, ry = (y & s) > 0;
		d += s * (ll)(s) * ((3 * rx) ^ ry);
		if (ry == 0) {
			if (rx == 1) x = N-1 - x, y = N-1 - y;
			swap(x, y);
		}
	}
	return d;
}
*/