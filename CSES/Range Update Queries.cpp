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

// https://cses.fi/problemset/task/1651

ll seg [4*MAXN];
ll lazy[4*MAXN];

void update(int no, int l, int r, int a, int b, int v){
	if(b <  l || r < a) return;
	if(a <= l && r <= b){ lazy[no] += v; return; }

	int m=(l+r)/2, e=no*2, d=no*2+1;

	update(e, l,   m, a, b, v);
	update(d, m+1, r, a, b, v);
}

ll query(int no, int l, int r, int pos){
	if(pos < l || r < pos) return 0;
	
	int m=(l+r)/2, e=no*2, d=no*2+1;

	if(lazy[no])
	{
		if(l == r) seg[no] += lazy[no];
		else{ lazy[e] += lazy[no]; lazy[d] += lazy[no];	}
		lazy[no] = 0;
	}
	
	if(l == r) return seg[no];

	return query(e, l, m, pos) + query(d, m+1, r, pos);
}

void build(int no, int l, int r, int pos, int v){
	if( pos < l || r < pos) return;
	if(l == r){ seg[no] = v; return; }

	int m=(l+r)/2, e=no*2, d=no*2+1;

	build(e, l,   m, pos, v);
	build(d, m+1, r, pos, v);
}

int main(){
	int n, q; cin >> n >> q;

	for(int i=1, x; i<=n; i++){
		cin >> x;
		build(1, 1, n, i, x);
	}

	int t, a, b, u, k;
	while(q--){
		cin >> t;

		if(t&1)
		{
			cin >> a >> b >> u;
			update(1, 1, n, a, b, u);
		} 
		else 
		{
			cin >> k;
			cout << query(1, 1, n, k) << endl;
		}
	}
	
	return 0;	
}
