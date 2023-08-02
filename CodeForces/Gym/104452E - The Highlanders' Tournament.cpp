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

int seg[4*MAXN];
int ativo[4*MAXN];

int query(int no, int l, int r, int a, int b){
	if( r <  a || b <  l ) return -INF;
	if( a <= l && r <= b) return seg[no];

	int m=(l+r)/2, e = no*2, d = no*2+1;

	return max(query(e, l, m, a, b), query(d, m+1, r, a, b));
}

void update(int no, int l, int r, int a, int b, int v){
	if( r <  a || b <  l ) return;
	if( l == r )
	{
		if(v != seg[no]){
			seg[no] = 0;
			ativo[no] = 0;
		}
		return;
	}

	int m=(l+r)/2, e = no*2, d = no*2+1;

	update(e, l,   m, a, b, v);
	update(d, m+1, r, a, b, v);

	seg[no] = max(seg[e], seg[d]);
	ativo[no] = ativo[e] + ativo[d];
}

void build(int no, int l, int r, vi &lista){
	if(l == r){
		seg[no] = lista[l-1];
		ativo[no] = 1;
		return;
	}

	int m=(l+r)/2, e = no*2, d = no*2+1;
	
	build(e, l,   m, lista);
	build(d, m+1, r, lista);

	seg[no] = max(seg[e], seg[d]);
	ativo[no] = ativo[e] + ativo[d];
}


int bbSeg(int no, int l, int r, int v){
	if(l == r) return l;

	int m=(l+r)/2, e = no*2, d = no*2+1;

	if(ativo[e] >= v) return bbSeg(e, l, m, v);
	else return bbSeg(d, m+1, r, v - ativo[e]);
}


int main(){
	optimize;
	int n, m;
	cin >> n >> m;

	vi lista(n);
	for(auto &x : lista) cin >> x;

	build(1, 1, n, lista);

	int l, r;
	while(m--){
		cin >> l >> r;

		l = bbSeg(1, 1, n, l);
		r = bbSeg(1, 1, n, r);

		int mx = query(1, 1, n, l, r);

		update(1, 1, n, l, r, mx);
	}

	for(int i=1, x; i<=n; i++){
		x = query(1, 1, n, i, i);
		if(x) cout << x << " ";
	}
	
	cout << endl;

	return 0;	
}
