#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e3 + 5;
using namespace std;

// A. Artwork
// https://codeforces.com/gym/102346/problem/A


int pai[MAXN], sz[MAXN];

inline int find(int u){
	return (pai[u] == -1 || pai[u] == u ? u : pai[u] = find(pai[u]));
}

inline void join(int u, int v){
	u = find(u);
	v = find(v);

	if(u == v) return;
	if(sz[v] > sz[u]) swap(u, v);

	pai[v] = u;	
	sz[u] += sz[v];
}

struct S{
	ll x, y, s;
	S(ll xx, ll yy, ll ss)
	{
		x = xx;
		y = yy;
		s = ss;
	}
};

int main(){

	int m, n, k;	
	cin >> m >> n >> k;
	
	memset(pai, -1, sizeof pai);
	for(int i=0; i<MAXN; i++) sz[i] = 1;

	vector<S> ss;

	for(int i=0, x, y, s; i<k; i++){ cin >> x >> y >> s; ss.emplace_back(x, y, s); }


	for(int i=0; i<k; i++)
	{
		for(int j=i+1; j<k; j++)
		{
			if(find(i) == find(j)) continue;

			ll dist = (ss[i].x-ss[j].x)*(ss[i].x-ss[j].x) + (ss[i].y-ss[j].y)*(ss[i].y-ss[j].y);

			//cerr << "dist " << i << " -: " << j << " = " << dist << " | " << ss[i].s*ss[i].s + ss[j].s*ss[j].s<< endl;

			if(  dist    <=    ss[i].s*ss[i].s   +    ss[j].s*ss[j].s   +   2*ss[i].s*ss[j].s    ) join(i, j);
		}

		//cerr << ss[i].x << " " << ss[i].y << " " << ss[i].s << endl;
		if( ss[i].x - ss[i].s <= 0) join(i, k+1);
		if( ss[i].x + ss[i].s >= m) join(i, k+2);
		if( ss[i].y + ss[i].s >= n) join(i, k+3);
		if( ss[i].y - ss[i].s <= 0) join(i, k+4);
	}

	// k+1 = esquerda
	// k+2 = direita
	// k+3 = cima
	// k+4 = baixo

	bool ok = false;
	if(find(k+1) == find(k+4)) ok = true;  // esquerda - baixo
	if(find(k+4) == find(k+3)) ok = true;  // baixo - cima
	if(find(k+1) == find(k+2)) ok = true;  // esquerda - direita
	if(find(k+3) == find(k+2)) ok = true;  // cima - direita

	//cerr << find(k+1) << " " << find(k+2) << " " << find(k+3) << " " << find(k+4);


	cout << (ok ? "N" : "S") << endl;

	return 0;	
}
