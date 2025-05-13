#include <bits/stdc++.h>
#define pii pair<int,int>
#define iii array<int, 3>
using namespace std;
const int MAXN = 2e5 + 5;
const int SQRT = 700;
// https://codeforces.com/contest/1217/problem/F

int pai[MAXN], sz[MAXN];

inline int find(int u){ return pai[u] == u ? u : pai[u] = find(pai[u]); }

void join(int u, int v){
	u = find(u), v = find(v);

	if(u == v) return;
	if(sz[v] > sz[u]) swap(u, v);

	pai[v] = u;
	sz[u] += sz[v];
}

int vis[MAXN], tim = 1;
set<int> grafo[MAXN];

bool dfs(int u, int s){
	if(u == s) return true;
	vis[u] = tim;
	for(auto v : grafo[u])
		if(vis[v] != tim && dfs(v, s))
			return true;
	return false;
}

int n, q; 
inline int eval(int u, int l){ return (u + l) % n; }

vector<pii> maybe;
bool countmaybe(pii x){
	auto it = lower_bound(begin(maybe), end(maybe), x);
	return (it != end(maybe)) && (*it == x);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;

	vector<iii> queries(q);
	for(auto &[t, u, v] : queries)
		cin >> t >> u >> v, u--, v--;
	
	set<pii> edges;
	vector<pii> eterno;
	for(int at=0, lst=0; at<q; at++)
	{
		if(at%SQRT == 0)
		{
			for(int i=0; i<=n; i++){
				grafo[i].clear();
				pai[i] = i;
				sz[i] = 1;
			}
			maybe.clear();

			for(auto &x : edges) eterno.push_back(x);
			edges.clear();
			

			for(int j=at; j<q && j<at+SQRT; j++)
				if(queries[j][0] == 1)
				{
					auto &[t, u, v] = queries[j];
					int tu = eval(u, 1), tv = eval(v, 1);

					maybe.emplace_back(min( u,  v), max( u,  v));
					maybe.emplace_back(min(tu, tv), max(tu, tv));
				}

			sort(begin(maybe), end(maybe));

			for(auto &[u, v] : eterno)
				if(!countmaybe(pii(u, v)))
					join(u, v);
				
			for(int j=0, u, v; j<eterno.size(); j++)
				if(countmaybe(eterno[j]))
				{
					edges.emplace(eterno[j]);
					
					u = find(eterno[j].first), v = find(eterno[j].second);
					if(u == v) continue;
					
					grafo[u].emplace(v);
					grafo[v].emplace(u);

					swap(eterno[j], eterno.back());
					eterno.pop_back();
					j--;
				}
		}

		auto &[t, u, v] = queries[at];
		u = eval(u, lst);
		v = eval(v, lst);
		if(u > v) swap(u, v);

		
		if(t&1)
		{
			if(edges.count(pii(u, v)))
			{
				edges.erase(pii(u, v));
				u = find(u), v = find(v);

				grafo[u].erase(v);
				grafo[v].erase(u);
			}
			else
			{
				edges.emplace(pii(u, v));
				u = find(u), v = find(v);
				
				if(u != v)
		  			grafo[u].emplace(v),
					grafo[v].emplace(u);
			}
		}
		else 
		{
			u = find(u), v = find(v);	
			cout << (lst = dfs(u, v));
		}
		tim++;
	}
	
	cout << "\n";

	return 0;	
}