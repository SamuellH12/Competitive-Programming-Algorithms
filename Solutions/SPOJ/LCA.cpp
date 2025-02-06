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

int read_int(){
	char r;
	bool start=false,neg=false;
	int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

//https://www.spoj.com/problems/LCA/

int n;

const int MAXLG = 10;

vi grafo[MAXN];
int bl[MAXLG][MAXN];
int lv[MAXN];

void dfs(int u, int p, int l)
{
	//cerr << p << "->" << u << " lv"  << l << endl;
	lv[u] = l;
	bl[0][u] = p;

	for(auto v : grafo[u])
		if(v != p)
			dfs(v, u, l+1);
}

void blCalc()
{
	for(int l=1; l<MAXLG; l++)
		for(int u=1; u<=n; u++)
			bl[l][u] = bl[l-1][bl[l-1][u]];	
}

int lca(int u, int v)
{
	if(u == v) return u;
	if(lv[u] < lv[v]) swap(u, v);
	
	//iguala o level
	for(int l=MAXLG-1; l >=0; l--)
		if(lv[u] - (1<<l) >= lv[v])
			u = bl[l][u];
	
	//cerr << u << "<=" << endl;
	if(u == v) return u;

	//anda até o último cara de cada um que não é Commom Ancestor
	for(int l=MAXLG-1; l >=0; l--)
		if(bl[l][u] != bl[l][v])
			u = bl[l][u],
			v = bl[l][v];


	return bl[0][u];
}

int main(){
	optimize;
	int t, caso=0;  t = read_int();
	lv[0] = -1;
	// O(T N LOG N)
	while(caso++ < t)
	{
		cout << "Case " << caso << ":\n";
		n = read_int();
		memset(bl, -1, sizeof bl);
		memset(lv, 0, sizeof lv);

		for(int u=1, m, v; u<=n; u++)
		{
			grafo[u].clear();
			 m = read_int();
			while(m--)
			{
				v = read_int();
				bl[0][v] = u;
				grafo[u].push_back(v);
			}
		}

		int root = 1;
		//O(N)
		for(int u=1; u<=n; u++)
			if(bl[0][u] == -1)
			{
				bl[0][u] = 0;
				root = u;
				break;
			}

		//N
		dfs(root, 0, 0);
		//N LOG N
		blCalc();

		int q, u, v;  q = read_int();
		//N LOG N
		while(q--)
		{
			u = read_int();
			v = read_int();
			//cout << u << "->" << v << " : ";
			cout << lca(u, v) << endl;
		}

	}
	
	return 0;	
}
