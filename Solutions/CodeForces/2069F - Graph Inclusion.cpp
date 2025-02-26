#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define pii pair<int,int>
const int MAXN = 4e5 + 5;
using namespace std;
// https://codeforces.com/contest/2069/problem/F

struct DSUr {
	vector<int> pai, sz, savept;
	stack<pair<int&, int>>  st;
	int cmp;
	DSUr(int n) : pai(n+1), sz(n+1, 1) {
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
		savept.pop_back();
	}
};

DSUr A, AUB;
vector<pii> seg[4*MAXN];
int lst;

void insert(int no, int l, int r, int a, int b, pii edge){
	if(b <  l || r <  a) return;
	if(a <= l && r <= b){ seg[no].emplace_back(edge); return; }

	int m = (l+r)/2;

	insert(no*2, l, m, a, b, edge);
	insert(no*2+1, m+1, r, a, b, edge);
}

void solve(int no, int l, int r){
	A.checkpoint();
	AUB.checkpoint();

	for(auto &[u, v] : seg[no]){
		AUB.join(abs(u), v);
		if(u < 0) A.join(abs(u), v);
	}

	if(l == r){ if(l != lst) cout << A.cmp - AUB.cmp << endl; }
	else {
		int m = (l+r)/2;
		solve(no*2, l, m);
		solve(no*2+1, m+1, r);
	}

	A.rollback();
	AUB.rollback();
}

int main(){
	optimize;
	int n, q;
	cin >> n >> q;

	char c;
	map<pii, int> acA, acB;
	for(int i=0, u, v; i<q; i++)
	{
		cin >> c >> u >> v;
		if(u > v) swap(u, v);
		pii edge(u, v);

		if(c == 'A')
		{
			edge.first *= -1;
			if(acA.count(edge)) 
			insert(1, 0, q, acA[edge], i-1, edge),
			acA.erase(edge);
			else acA[edge] = i;
		} else 
		{
			if(acB.count(edge)) 
				insert(1, 0, q, acB[edge], i-1, edge),
				acB.erase(edge);
			else acB[edge] = i;
		}
	}

	for(auto [uv, l] : acA) insert(1, 0, q, l, q, uv);
	for(auto [uv, l] : acB) insert(1, 0, q, l, q, uv);
	
	A = DSUr(n);
	AUB = DSUr(n);
		
	lst = q;
	solve(1, 0, q);

	return 0;	
}
