#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
// https://codeforces.com/contest/1932/problem/F


int main(){
	optimize;
	int t; cin >> t;
	while(t--){

		int n, m;
		cin >> n >> m;

		vii lf, rg, cat;

		for(int i=0, l, r; i<m; i++)
		{
			cin >> l >> r;
			lf.emplace_back(l, i);
			rg.emplace_back(r, i);
			cat.emplace_back(l, r);
		}

		sort(ALL(lf));
		sort(ALL(rg));

		vi memo(n+10, 0);
		multiset<int> ativos;

		for(int i=1, li=0, ri=0; i<=n; i++)
		{
			while(li < m && lf[li].first <= i) ativos.emplace(lf[li++].first); //adicionar ativos
			int lst = ativos.empty() ? i-1 : *ativos.begin() - 1;
			
			//no feed
			memo[i] = memo[i-1];

			//feed
			memo[i] = max(memo[i], memo[lst] + (int)ativos.size());
			
			while(ri < m && rg[ri].first <= i) ativos.erase(ativos.find( cat[rg[ri++].second].first )); //remover inativos
		}

		cout << memo[n] << endl;
	}
	
	return 0;	
}


// Ideia: mantem os gatos ativos no momento atual. A DP 
// então é o máximo entre não alimentar os gatos ou alimentar
// alimentar significa a quantidade atual de gatos mais o maximo 
// do último momento em que nenhum dos gatos atuais estavam ativos