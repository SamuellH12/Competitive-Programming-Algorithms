#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define INF 0x3f3f3f3f
const int MAXN = 3e5 + 10;
using namespace std;

// https://codeforces.com/gym/101879/problem/C

int pai[MAXN];

int find(int u){
	 return pai[u] == u ? u : pai[u] = find(pai[u]);
}

void join(int u, int v){
	u = find(u);
	v = find(v);
	pai[u] = v;
}

bool vis[MAXN];

vi grafo [MAXN];
int grau[MAXN];
vii ans;

void dfs(int u, int p){
	vis[u] = true;

	for(auto v : grafo[u])
	{
		if(v == p) continue;

		dfs(v, u);

		if(grau[v]&1)
		{
			grau[u]++;
			grau[v]++;
			ans.emplace_back(u, v);
		}
	}
}


int main(){
	optimize;
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int i=0; i<=n; i++) pai[i] = i;

	for(int i=0, u, v; i<m; i++){
		cin >> u >> v;

		grau[u]++;
		grau[v]++;
	}

	vii arestas;

	for(int i=0, u, v; i<k; i++)
	{
		cin >> u >> v;
		arestas.emplace_back(u, v);
	}

	for(auto [u, v] : arestas)
		if(find(u) != find(v))
		{
			join(u, v);
			grafo[u].push_back(v);
			grafo[v].push_back(u);
		}


	for(int i=n; i; i--)
		if(grau[i]&1 && !vis[i])
			dfs(i, 0);


	int ni = 0;
	for(int i=1; i<=n; i++) ni += grau[i]&1;

	if(ni)
	{
		cout << "NO" << endl;
		return 0;
	}


	cout << "YES" << endl;

	cout << ans.size() << endl;

	for(auto [u, v] : ans) cout << u << " " << v << endl;

	
	return 0;	
}

/*
A base da ideia é que:

1 - Dado o grafo original é possível determinar o grau de cada vértice (e a paridade)
2 - Temos de escolher arestas opcionais para alterar a paridade dos vértices ímpares
3 - O mais importante: o subespaço de possibilidades gerado pelo grafo opcional completo 
	é o mesmo que o gerado por uma Árvore Geradora qualquer desse grafo.
4 - Dada a observação do 3 e a imposição do 2, fica fácil perceber que podemos apenas
	pegar arestas de forma gulosa a partir das folhas da árvore e retornar para a raíz com
	a mesma estratégia.

*/