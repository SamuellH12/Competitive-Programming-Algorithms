#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 1e5 + 5;

vector<int> grafo[MAXN];
deque<int> distToAncestor[MAXN];

bool rem[MAXN];
int szt[MAXN], parent[MAXN];

void getDist(int u, int p, int d=0){
	for(auto v : grafo[u])
		if(v != p && !rem[v])
			getDist(v, u, d+1);
	distToAncestor[u].emplace_front(d);
}

int getSz(int u, int p){
	szt[u] = 1;
	for(auto v : grafo[u])
		if(v != p && !rem[v])
			szt[u] += getSz(v, u);
	return szt[u];
}

void dfsc(int u=0, int p=-1, int f=-1, int sz=-1){
	if(sz < 0) sz = getSz(u, -1); //starting new tree
	
	for(auto v : grafo[u])
		if(v != p && !rem[v] && szt[v]*2 >= sz)
			return dfsc(v, u, f, sz);

	rem[u] = true, parent[u] = f;
	getDist(u, -1, 0); //get subtree dists to centroid
	
	for(auto v : grafo[u])
		if(!rem[v]) 
			dfsc(v, u, u, -1);
}

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		u--, v--;
		grafo[u].emplace_back(v);
		grafo[v].emplace_back(u);
	}

	dfsc();

	vector<pair<int, int>> closer(n, {INF, INF});
	auto paint = [&](int u){
		int p = u, i=0;
		while(~p){
			closer[p] = min(closer[p], {distToAncestor[u][i], u});
			p = parent[p]; i++;
		}
	};
	auto getCloser = [&](int u){
		int p = u, i=0;
		pair<int, int> ans = closer[u];
		while(~p){
			ans = min(ans,{closer[p].first + distToAncestor[u][i], closer[p].second});
			p = parent[p]; i++;
		}
		return ans.second;
	};

	vector<int> ans(n);
	ans[n-1] = n-1;
	paint(n-1);

	for(int u=n-2; ~u; u--)
		ans[u] = getCloser(u),
		paint(u);

	for(auto &x : ans) cout << x+1 << " ";
	cout << "\n";
}
