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
// https://codeforces.com/contest/932/problem/F

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	static const ll inf = LLONG_MAX; // Double: inf = 1/.0, div(a,b) = a/b
	ll div(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } //floored division
	
	bool isect(iterator x, iterator y) {
		if(y == end()) return x->p = inf, 0;
		if(x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	
	void add_line(ll k, ll m){ // kx + m  //if minimum k*=-1, m*=-1, query*-1
		k*=-1LL, m*=-1LL;
		auto z = insert({k, m, 0}), y = z++, x = y;
		while(isect(y, z)) z = erase(z);
		if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	
	ll query(ll x) {
		if(empty()) return 0;
		assert(!empty());
		auto l = *lower_bound(x);
		return (l.k * x + l.m)*-1LL;
	}
};

vi grafo[MAXN];
ll a[MAXN], b[MAXN];
LineContainer lc[MAXN];
ll ans[MAXN];

void dfs(int u, int p=-1){
	
	for(auto v : grafo[u])
		if(v != p)
		{
			dfs(v, u);
			if(lc[u].size() < lc[v].size()) swap(lc[u], lc[v]);
			for(auto& [k, m, p] : lc[v]) lc[u].add_line(-k, -m);
		}

	ans[u] = lc[u].query(a[u]);
	lc[u].add_line(b[u], ans[u]);
}

int main(){
	optimize;
	int n; cin >> n;

	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) cin >> b[i];

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		grafo[u].emplace_back(v);
		grafo[v].emplace_back(u);
	}

	dfs(1);
	
	for(int i=1; i<=n; i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;	
}
