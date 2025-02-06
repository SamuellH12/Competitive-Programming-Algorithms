#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e5 + 5;
using namespace std;
// https://codeforces.com/contest/321/problem/C

vector<int> grafo[MAXN];
deque<int> distToAncestor[MAXN];

bool rem[MAXN];
int szt[MAXN], parent[MAXN];
char rnk[MAXN];

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
	rnk[u] = rnk[f]+1;
	getDist(u, -1, 0); //get subtree dists to centroid
	
	for(auto v : grafo[u])
		if(!rem[v]) 
			dfsc(v, u, u, -1);
}

int main(){
	optimize;
	int n; cin >> n;

	for(int i=1, u, v; i<n; i++)
	{
		cin >> u >> v;
		grafo[u].emplace_back(v);
		grafo[v].emplace_back(u);
	}
	
	rnk[0] = 'A'-1;
	dfsc(1, -1, 0, -1);

	for(int i=1; i<=n; i++) cout << rnk[i] << " ";
	cout << endl;
	
	return 0;	
}
