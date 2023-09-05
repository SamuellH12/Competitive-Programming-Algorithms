#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6;
using namespace std;

// https://cses.fi/problemset/task/1649

int seg [4*MAXN];

void update(int no, int l, int r, int pos, int v){
	if(pos < l || pos > r) return;
	if(l == r){seg[no] = v; return;}

	int m=(l+r)/2, e=no*2, d=no*2+1;

	update(e, l,   m, pos, v);
	update(d, m+1, r, pos, v);
	
	seg[no] = min(seg[e], seg[d]);
}

int query(int no, int l, int r, int a, int b){
	if(b <  l || r <  a) return INF;
	if(a <= l && r <= b) return seg[no];

	int m=(l+r)/2, e=no*2, d=no*2+1;

	return min(query(e, l, m, a, b), query(d, m+1, r, a, b));
}

void build(int no, int l, int r, int a[]){
	if(l == r){ seg[no] = a[l]; return; }

	int m=(l+r)/2, e=no*2, d=no*2+1;

	build(e, l  , m, a);
	build(d, m+1, r, a);

	seg[no] = min(seg[e], seg[d]);
}

int main(){
	int n, q;
	cin >> n >> q;

	int lista [n+1];
	for(int i=1, x; i<=n; i++)	
		cin >> lista[i];

	build(1, 1, n, lista);

	int o, a, b;
	while(q--)
	{
		cin >> o >> a >> b;

		if(o&1) update(1, 1, n, a, b);
		else cout << query(1, 1, n, a, b)<< endl;
	}
	
	return 0;	
}
