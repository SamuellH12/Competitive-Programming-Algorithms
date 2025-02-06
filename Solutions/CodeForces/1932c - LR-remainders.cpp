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
// https://codeforces.com/contest/1932/problem/C

#define int ll

int MOD;
int seg[4*MAXN];


int query(int no, int l, int r, int a, int b){
	if(b <  l || r <  a) return 1;
	if(a <= l && r <= b) return seg[no];

	int m=(l+r)/2, e=no*2, d=no*2+1;

	return (query(e, l, m, a, b) * query(d, m+1, r, a, b)) % MOD;
}

void update(int no, int l, int r, int pos, int v){
	if(pos < l || r < pos) return;
	if(l == r){seg[no] = v; return; }

	int m=(l+r)/2, e=no*2, d=no*2+1;

	update(e, l,   m, pos, v);
	update(d, m+1, r, pos, v);

	seg[no] = (seg[e] * seg[d]) % MOD;
}

void build(int no, int l, int r, vector<int> &lista){
	if(l == r){ seg[no] = lista[l-1] % MOD; return; }

	int m=(l+r)>>1, e=no*2, d=no*2+1;

	build(e, l,   m, lista);
	build(d, m+1, r, lista);
	
	seg[no] = (seg[e] * seg[d]) % MOD;
}

int32_t main(){
	optimize;
	int t; cin >> t;
	while(t--){

		int n; 
		cin >> n >> MOD;
		string s;
		vi sla(n);

		for(auto &x : sla) cin >> x;

		build(1, 1, n, sla);

		cin >> s;

		//cerr << "-> ";
		int l=1, r=n;
		for(int i=0; i<n; i++)
		{
			cout << query(1, 1, n, l, r) % MOD << " ";
			
			if(s[i] == 'L') l++;
			else r--;
		}

		cout << endl;
	}
	
	return 0;	
}
