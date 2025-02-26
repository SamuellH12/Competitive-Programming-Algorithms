#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define pii pair<int,int>
const int MAXN = 300000 + 5;
using namespace std;
// https://codeforces.com/gym/100551/problem/A

struct DSUr {
	vector<int> pai, sz, savept; //save point
	stack<pair<int&, int>>  st;
	int cmp;
	DSUr(int n) : pai(n+1), sz(n+1, 1), savept(1, 0) {
		for(int i=0; i<=n; i++) pai[i] = i;
		cmp = n;
	}
	DSUr(){}
	
	int find(int u){ return pai[u] == u ? u : find(pai[u]); }

	void join(int u, int v){
		u = find(u), v = find(v);
		
		if(u == v) return;
		if(sz[v] > sz[u]) swap(u, v);

		save(cmp); cmp--;
		save(pai[v]); pai[v] = u;
		save(sz[u]);  sz[u] += sz[v];
	}
	
	void save(int &x){ st.emplace(x, x); }
	void pop(){
		st.top().first = st.top().second; st.pop();
		st.top().first = st.top().second; st.pop();
		st.top().first = st.top().second; st.pop();
	}

	void checkpoint(){ savept.push_back(st.size()); }
	void rollback(){
		while(st.size() > savept.back()) pop();
		if(savept.back()) savept.pop_back();
	}
};

DSUr dsu;
vector<pii> seg[4*MAXN];

void insert(int no, int l, int r, int a, int b, pii edge){
	if(b <  l || r <  a) return;
	if(a <= l && r <= b){ seg[no].emplace_back(edge); return; }

	int m = (l+r)/2;

	insert(no*2,   l,   m, a, b, edge);
	insert(no*2+1, m+1, r, a, b, edge);
}

void walk(int no, int l, int r){
	dsu.checkpoint();
	int q=0;
	
	for(auto [u, v] : seg[no]){
		if(u == -1) q++;
		else dsu.join(u, v);
	}

	while(q--) cout << dsu.cmp << endl;
	
	if(l < r){
		int m = (l+r)/2;
		walk(no*2, l, m);
		walk(no*2+1, m+1, r);
	}
	dsu.rollback();
}

int main(){
	optimize;
	freopen("connect.in", "r", stdin);
	freopen("connect.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	dsu = DSUr(n);
	
	char c;
	map<pii, int> ativas;
	for(int i=0, u, v; i<k; i++)
	{
		cin >> c;
		if(c == '?') insert(1, 0, k, i, i, pii(-1, -1));
		else 
		{
			cin >> u >> v;
			if(u > v) swap(u, v);
			pii edge(u, v);

			if(ativas.count(edge))
				insert(1, 0, k, ativas[edge], i, edge),
				ativas.erase(edge);
			else 
				ativas[edge] = i;
		}
	}

	for(auto [uv, l] : ativas) insert(1, 0, k, l, k, uv);
	
	walk(1, 0, k);

	return 0;	
}
