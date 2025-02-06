#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
const int MAXN = 2 * 1e5 + 5;
//https://atcoder.jp/contests/abc288/tasks/abc288_c

int n, m, resp = 0;
int pai[MAXN];

int find(int u){ return (pai[u]==-1 ? u : pai[u] = find(pai[u])); }
void join(int u, int v){
	u = find(u);
	v = find(v);
	pai[u] = v;
}


int main(){
	memset(pai, -1, sizeof pai);
	cin >> n >> m;

	for(int i=0, u, v; i<m; i++){
		cin >> u >> v;
		
		if(find(u) == find(v)) resp++;
		else join(u, v);
	}

	cout << resp << endl;
	
	return 0;	
}
