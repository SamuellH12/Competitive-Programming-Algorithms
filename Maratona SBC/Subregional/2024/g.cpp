#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
#define vi vector<ll>
#define pii pair<int,int>
#define INF (0x3f3f3f3f)
const int MAXN = 2e5 + 5;
using namespace std;
// https://codeforces.com/gym/105327/problem/G

pii seg[4*MAXN];
pii query(int no, int l, int r, int a, int b){
	if(b <  l || r <  a) return {-INF, -INF};
	if(a <= l && r <= b) return seg[no];
	int m=(l+r)>>1, e=no<<1, d=e+1;
	return max(query(e, l, m, a, b), query(d, m+1, r, a, b));
}
void update(int no, int l, int r, int pos, pii v){
	if(pos < l || r < pos) return; 
	if(l == r){seg[no] = v; return; }	
	int m=(l+r)>>1, e=no<<1, d=e+1;
	if(l  <= pos && pos <= m) update(e, l,   m, pos, v); 
	if(m+1<= pos && pos <= r) update(d, m+1, r, pos, v);
	seg[no] = max(seg[e], seg[d]);
}
//
const int MAXB = 1e5 + 10;
ll bit[MAXB];
void update(int pos, ll val){
	for(; pos < MAXB; pos += pos&(-pos))
		bit[pos] += val;
}
ll query(int pos){
	ll sum = 0;
	for(; pos > 0; pos -= pos&(-pos))
		sum += bit[pos];
	return sum;
}
/////

pii g[MAXN];
int pai[MAXN], fim[MAXN];
int tin[MAXN], tout[MAXN];
int n; 

inline ll subsum(int u){ return query(tout[u]) - query(tin[u]-1); }

int cnt = 1;
int l[MAXB];

int dfs(int u){
	if(u <= n)
	{
		tin[u] = tout[u] = cnt++;
		fim[u] = u; 
		update(1, 1, n, tin[u], pii(u, u));
		update(tin[u], l[u]);
		return u;
	}

	tin[u] = cnt;
	int v = dfs(g[u].first);
	int w = dfs(g[u].second);
	tout[u] = cnt-1LL;
	

	ll sb1 = subsum(g[u].first);
	ll sb2 = subsum(g[u].second);

	if(sb1 > sb2 || (sb1 == sb2 && v < w))
	{
		fim[v] = u;
		update(1, 1, n, tin[v], pii(fim[v], v));
		return v;
	}

	fim[w] = u;
	update(1, 1, n, tin[w], pii(fim[w], w));
	return w;
}

int32_t main(){
	optimize;
	cin >> n;	

	for(int i=1; i<=n; i++) cin >> l[i];

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		g[n+i] = {u, v};
		pai[u] = pai[v] = n+i;
	}

	int root = n+n-1LL;
	cout << dfs(root) << endl;	

	int q; cin >> q;
	while(q--)
	{
		int u, x; cin >> u >> x;
		
		update(tin[u], x);

		while(fim[u] != root) //no máximo LOG S mudanças no caminho // em um caminho, toda vez que a cor muda a soma dobra (pq o nó irmão tem subsum >= atual)
		{
			auto [f1, f2] = g[pai[fim[u]]];
			if(f1 != fim[u]) swap(f1, f2);

			ll sb1 = subsum(f1), sb2 = subsum(f2);
			int c2 = abs(query(1, 1, n, tin[f2], tout[f2]).second);

			//troca os finais
			if(sb1 > sb2) // cuidado com o enunciado, o desempate está mal informado
			{
				fim[u] = fim[c2]; update(1, 1, n, tin[u],  pii(fim[u],   u));
				fim[c2] = f2;     update(1, 1, n, tin[c2], pii(fim[c2], c2));
			}
			//troca o u
			else u = c2;
		}

		cout << u << endl;
	}

	return 0;	
}