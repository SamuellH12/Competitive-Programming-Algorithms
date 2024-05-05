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
// https://codeforces.com/gym/104767/problem/E

unordered_map<int, int> seg[4*MAXN];

void build(int no, int l, int r, vi& lista){
	if(l == r){
		int k = lista[l-1];
		for(int d=2; d*d <= k; d++)
			if(k%d == 0)
			{
				int tot = 0;
				while(k%d == 0)	k /= d, tot++;
				seg[no][d] += tot;
			}

		if(k > 1) seg[no][k]++;
		return;
	}

	int m=(l+r)/2, e=2*no, d=e+1;

	build(e, l, m, lista);
	build(d, m+1, r, lista);

	if(seg[d].size() > seg[e].size())
	{
		seg[no] = seg[d];
		for(auto [k, v] : seg[e]) seg[no][k] += v;
	}
	else
	{
		seg[no] = seg[e];
		for(auto [k, v] : seg[d]) seg[no][k] += v;
	}
}

int query(int no, int l, int r, int a, int b, int k){
	if(b <  l || r <  a) return 0;
	if(a <= l && r <= b) return (seg[no].find(k) != seg[no].end() ? seg[no][k] : 0);

	int m=(l+r)/2, e=2*no, d=e+1;

	return query(e, l, m, a, b, k) + query(d, m+1, r, a, b, k);
}


int main(){
	optimize;
	int n; cin >> n;

	vi sla(n);
	for(auto &x : sla) cin >> x;

	build(1, 1, n, sla);

	int q, l, r, k; 
	cin >> q;

	while(q--)
	{
		cin >> l >> r >> k;

		bool ok = true;

		for(int d=2; d*d <= k && ok; d++)
			if(k%d == 0)
			{
				int cnt = query(1, 1, n, l, r, d);
				int tot = 0;
				while(k%d == 0)	k /= d, tot++;
				ok &= tot <= cnt;
			}

		if(k > 1) ok &= query(1, 1, n, l, r, k) > 0;

		cout << (ok ? "Yes" : "No") << endl;
	}

	
	return 0;	
}