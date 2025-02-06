#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 2e5 + 5;
using namespace std;
// https://codeforces.com/contest/1899/problem/G

int idx[MAXN];
int tin[MAXN], tout[MAXN], val[MAXN], tim=1;
vi grafo[MAXN];

vi seg[4*MAXN];

void build(int no, int l, int r){
	seg[no].clear();
	if(l == r) return seg[no].push_back(val[l]);

	int m=(l+r)>>1, e=2*no, d=e+1;

	build(e, l, m);
	build(d, m+1, r);

	int i=0, j=0;
	while(i < seg[e].size() && j < seg[d].size())
		if(seg[e][i] < seg[d][j]) seg[no].push_back(seg[e][i++]);
		else seg[no].push_back(seg[d][j++]);

	while(i < seg[e].size())seg[no].push_back(seg[e][i++]);
	while(j < seg[d].size())seg[no].push_back(seg[d][j++]);
}

bool query(int no, int l, int r, int a, int b, int mn, int mx)
{
	if(b <  l || r <  a) return false;
	if(a <= l && r <= b){
		auto it = lower_bound(ALL(seg[no]), mn);

		if(it != seg[no].end() && *it <= mx) return true;
		return false;
	}

	int m=(l+r)>>1, e=2*no, d=e+1;

	return query(e, l, m, a, b, mn, mx) || query(d, m+1, r, a, b, mn, mx);
}


void dfs(int u, int p){
	tin[u] = val[idx[u]] = tim++;

	for(auto v : grafo[u])
		if(v != p) 
			dfs(v, u);
	
	tout[u] = tim++;
}

int main(){
	optimize;
	int t; cin >> t;
	while(t--){

		int n, q; cin >> n >> q;
		tim = 1;

		for(int i=0; i<=n; i++) grafo[i].clear();

		for(int i=1,u, v; i<n; i++){ 
			cin >> u >> v;
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}

		for(int i=1, p; i<=n; i++)
		{
			cin >> p;
			idx[p] = i;
		}

		dfs(1, -1);

		build(1, 1, n);

		int l, r, x;
		while(q--)
		{
			cin >> l >> r >> x;
			// cerr << "aqui" << endl;
			cout << (query(1, 1, n, l, r, tin[x], tout[x]) ? "YES" : "NO") << endl;
		}

		cout << endl;
	}
	
	return 0;	
}
