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
// https://codeforces.com/contest/631/problem/E

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
		auto z = insert({k, m, 0}), y = z++, x = y;
		while(isect(y, z)) z = erase(z);
		if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
	}
	
	ll query(ll x) {
		if(empty()) return -INF;
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};


int main(){
	optimize;
	int n; cin >> n;

	vector<ll> sla(n+1), ps(n+1, 0);
	ll tot = 0;

	for(int i=1; i<=n; i++)
	{
		cin >> sla[i];
		ps[i] = ps[i-1] + sla[i];
		tot += sla[i]*i;
	}

	LineContainer cht;
	ll ans = 0;

	for(int i=1; i<=n; i++)
	{
		ans = max(ans, cht.query(sla[i]) +  ps[i-1] - sla[i]*i);
		cht.add_line(i, -ps[i-1]);
	}

	cht.clear();

	for(int i=n; i; i--)
	{
		ans = max(ans, cht.query(sla[i]) +  ps[i] - sla[i]*i);
		cht.add_line(i, -ps[i]);
	}

	cout << tot + ans << endl;
	
	return 0;	
}
