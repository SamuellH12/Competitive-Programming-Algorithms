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
// https://codeforces.com/gym/104767/problem/H

const int BLOCK = 750;


int main(){
	optimize;
	int n, m, q; 
	cin >> n >> m >> q;

	vi d(n), e(n), df(n);

	for(int i=0; i<n; i++) cin >> d[i];
	for(int i=0; i<n; i++) cin >> e[i];

	vector<vi> grafo(n);

	for(int i=0, u, v;  i <m; i++)
	{
		cin >> u >> v;
		u--, v--;
		grafo[u].push_back(v);
		grafo[v].push_back(u);
	}

	for(int i=0; i<n; i++) sort(ALL(grafo[i]));

	auto recalc = [&](){
		df = vi(n, 0);
		for(int i=0; i<n; i++)
		{
			df[i] = d[i] - e[i];
			for(auto v :grafo[i])
				df[i] += d[v] - e[v];	
			//cerr << df[i] << " ";
		}
		// cerr << endl;	
	};
	recalc();


	int cnt = 0;
	vector<pii> ops;
	string op, tp;

	while(cnt++ < q)
	{
		if(cnt % BLOCK == 0)
		{
			recalc();
			// ops.assign(n, 0);
			ops.clear();
		}

		cin >> op;

		if(op == "add")
		{
			int x, u;
			cin >> x >> tp >> u;
			u--;
			if(tp == "desk") ops.emplace_back(u, x), d[u] += x;
			else ops.emplace_back(u, -x), e[u] += x;
		}
		else
		{
			int u; cin >> u; u--;
			int ans = df[u];

			for(auto [v, x] : ops)
			{
				if(v == u){ ans += x; continue; }

				auto it = lower_bound(ALL(grafo[u]), v);
				if(it == grafo[u].end() || *it != v) continue;

				ans += x;
			}

			if(ans == 0) cout << "same" << endl;
			else cout << (ans > 0 ? "desks" : "monitors") << endl;
		}

	}
	
	
	
	return 0;	
}
