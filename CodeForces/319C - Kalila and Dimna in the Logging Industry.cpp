#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
//https://codeforces.com/contest/319/problem/C

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
	
	void add_line(ll k, ll m){ // kx + m
		auto z = insert({k, m, 0}), y = z++, x = y;
		while(isect(y, z)) z = erase(z);
		if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

int main(){
	optimize;
	int n; 
	cin >> n;

	vector<ll> a(n), b(n);
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;

	LineContainer cht;
	cht.add_line(-b[0], 0);
	ll ans = 0;

	for(int i=1; i<n; i++)
	{
		ll f = ans = -cht.query(a[i]);
		cht.add_line(-b[i], -f);
	}

	cout << ans << endl;

	return 0;	
}
