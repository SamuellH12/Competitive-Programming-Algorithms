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
// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
int pai[MAXN], sz[MAXN], pts[MAXN];
vi lista[MAXN];

int find(int u){ return pai[u] == u ? u : pai[u] = find(pai[u]);  }
void join(int u, int v)
{
	u = find(u);
	v = find(v);

	if(u == v) return;
	if(sz[u] < sz[v]) swap(u, v);
	
	for(auto w : lista[v])
		pts[w] += pts[v] - pts[u],
		lista[u].push_back(w);
	
	pts[v] += -pts[u];
	lista[u].push_back(v);
 
	pai[v] = u;
	sz[u] += sz[v];
}

int main(){
	optimize;
	int n, m;
	cin >> n >> m;

	for(int i=1; i<=n; i++) pai[i] = i, sz[i] = 1;

	string s;
	int x, y, v;
	while(m--)
	{
		cin >> s >> x;

		if(s[0] == 'g')      cout << pts[x] + ( x == find(x) ? 0 : pts[find(x)]) << endl;
		else if(s[0] == 'j') cin >> y, join(x, y);
		else                 cin >> v, pts[find(x)] += v;
	}

	return 0;	
}
