#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 600;
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p1/2019/f3/linhas/

vi linha[MAXN];
vi terminal[MAXN];

int main(){
	optimize;
	
	int T, L, o, d;
	cin >> T >> L >> o >> d;


	for(int i=1, c; i<=L; i++){
		cin >> c;

		for(int j=0, t; j<c; j++)
		{
			cin >> t;

			terminal[t].push_back(i);
			linha[i].push_back(t);
		}
	}


	
	vi dist(L+1, INF);
	vector<bool> vis(L+1, false);
	vector<bool> tis(T+1, false);

	queue<int> fila;

	tis[o] = true;

	for(auto l : terminal[o])
	{
		dist[l] = 0;
		vis[l] = true;
		fila.push(l);
	}


	while(!fila.empty())
	{

		int l = fila.front();
		fila.pop();

		
		for(auto t : linha[l])
		{
			if(tis[t]) continue;
			tis[t] = true;

			for(auto nxt : terminal[t])
			{
				if(vis[nxt]) continue;

				dist[nxt] = dist[l] + 1;
				vis[nxt] = true;
				fila.push(nxt);
			}
		}
	}

	int ans = INF;

	for(auto l : terminal[d])
		ans = min(ans, dist[l]);

	cout << ans+1 << endl;
	
	return 0;	
}
