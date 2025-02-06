#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
// https://codeforces.com/contest/1932/problem/G

#define int ll

ll extGcd(ll a, ll b, ll &x, ll &y){
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	else
	{
		ll g = extGcd(b, a % b, y, x);
		y -= (a / b) * x;
		return g;
	}
}

int inv(int a, int mod){
	ll inv_x, y;
	extGcd(a, mod, inv_x, y);
	return (inv_x%mod + mod)%mod;		
}

// Retorna B / A (MOD H), mesmo que A e H não sejam coprimos (ainda pode haver resposta)
// No caso de não existir resposta, retorna INF
inline int inv_geral(int a, int b, int h){ // h = mod
	int gcd = __gcd(a, h);
	if(b%gcd) return INF;
			
	int md2 = h/gcd;

	return ((b/gcd) * (inv(a, h)) + md2) % md2;
}

int32_t main(){
	optimize;
	int t; cin >> t;
	while(t--){

		int n, m, h;
		cin >> n >> m >> h;

		vector<vector<pii>> grafo(n+1);
		vi lvl(n+1), add(n+1);

		for(int i=1; i<=n; i++)	cin >> lvl[i];
		for(int i=1; i<=n; i++)	cin >> add[i];

		for(int i=0, u, v; i<m; i++)
		{
			cin >> u >> v;
			grafo[u].emplace_back(v, INF);
			grafo[v].emplace_back(u, INF);
		}

		auto custo = [&](int u, int v, int delta){
			delta %= h;
			
			int a = (add[u] - add[v] + h) % h;
			
			int lu = (lvl[u] + add[u]*delta) % h, 
			    lv = (lvl[v] + add[v]*delta) % h ;

			int b = (lv - lu + h) % h;

			int ans = inv_geral(a, b, h);
			return ans;
		};
	
		auto dijkstra = [&](int s, int t){
			vi dist (n+1, INF);

			priority_queue<pii, vector<pii>, greater<pii>> fila;
			fila.push({0, s});
			dist[s] = 0;

			while(!fila.empty())
			{
				auto [d, u] = fila.top();
				fila.pop();

				if(d > dist[u]) continue;

				for(auto [v, c] : grafo[u]){
					if(dist[u]+1 > dist[v]) continue;

					c = custo(u, v, dist[u]) + 1;
					
					if( dist[v] > dist[u] + c )
					{			
						dist[v] = dist[u] + c;
						fila.push({dist[v], v});
					}
				}
			}

			return dist[t];
		};


		ll ans = dijkstra(1, n);

		cout << (ans < INF ? ans : -1 ) << endl;
	}
	
	return 0;	
}


/*

g = gcd(a, mod)

b / a ≡ (b/g) * inv(a/g)  (MOD mod)

Se e somente se b % g == 0

*/