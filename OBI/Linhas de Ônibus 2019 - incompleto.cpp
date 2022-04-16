#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 550
#define INF 100010
#define debug cout<<"ate aqui ok\n"
using namespace std;

int t, l, o, d; 
vi term [MAXN]; //mostra todos os terminais por quais passa a linha
vi linha[MAXN]; //mostra todas as linhas a partir de um terminal
vi grafo[MAXN];


int dijks(int ori)
{	int dist[l+1];
	bool vis[l+1];
	memset(dist, -1, sizeof dist);
	memset(vis, false, sizeof vis);
	priority_queue<int, vector<int>, greater<int>> fila;

	dist[ori] = 1;
	fila.push(ori);

	while(!fila.empty())
	{
		int atual = fila.top(); fila.pop();

		if(vis[atual]) continue;
		vis[atual] = true;

		for(auto a : grafo[atual])
		{
			if(dist[a] == -1 || dist[a] > dist[atual] + 1)
			{
				dist[a] = dist[atual] + 1;
				fila.push(a);
			}
		}

	}

	int resp = INF;
	for(auto b : linha[d]){
		resp = min(resp, dist[b]);
	}

	return resp;
}


int main(){
	optimize;
	cin>>t>>l>>o>>d;
		
	for(int li=1; li<=l; li++)
	{
		int aux; cin>>aux;
		for(int e=0; e<aux; e++)
		{
			int ter; cin>>ter;
			term[li].push_back(ter);
			linha[ter].push_back(li);
		}
	}

	for(int ter=1; ter<=t; ter++){
		for(int e : linha[ter]){
			for(int o : linha[ter]){
				if(e != o){
					grafo[e].push_back(o);
					grafo[o].push_back(e);
				}
			}
		}
	}

	int resp = INF;
	for(auto a : linha[o]){
		if(resp == 1) break;
		resp = min(resp, dijks(a));
	}

	cout<<resp;

	return 0;	
}
