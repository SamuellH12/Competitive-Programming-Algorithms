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

int pai[MAXN], sz[MAXN], tim[MAXN], t=1;

inline int find(int u, int q = INT_MAX){ 
	if( pai[u] == u || pai[u] == -1 || q < tim[u] ) return u;
	return find(pai[u], q); 
}

inline void join(int u, int v){
	u = find(u);
	v = find(v);

	if(u == v) return;
	if(sz[v] > sz[u]) swap(u, v);

	pai[v] = u;
	tim[v] = t++;
	sz[u] += sz[v];
}

inline void resetDSU(){
	memset(pai, -1, sizeof pai);
	for(int i=0; i<MAXN; i++) sz[i] = 1;
	memset(tim, 0, sizeof tim);
}

int main(){
	resetDSU();

	int n, m, s;
	cin >> n >> m >> s;

	vector<pair<int, pii>> arestas(m);

	for(auto &a : arestas) 
		cin >> a.second.first >> a.second.second >> a.first;

	sort(ALL(arestas));
	reverse(ALL(arestas));


	vi pesos;

	for(auto [w, a] : arestas)
		if(find(a.first) != find(a.second)){
			pesos.push_back(w);
			join(a.first, a.second);
		}

	
	int l, h;
	while(s--)
	{
		cin >> l >> h;

		int e=1, d=t, m, ans=1, u, v;

		while(e <= d)
		{
			m = (e+d) / 2;

			u = find(l, m);
			v = find(h, m);

			if(u == v){
				ans = m;
				d = m-1;
			}
			else
				e = m + 1;
		}

		cout << pesos[ans-1] << endl;
	}
	
	
	return 0;	
}
