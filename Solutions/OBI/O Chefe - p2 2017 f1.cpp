#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 550
#define INF 10000
#define debug cerr<<"ate aqui ok\n"
using namespace std;


vi  chefe[MAXN];	//em qual posição do array estão os chefes da pessoa
int pcargo[MAXN];	//quem é a pessoa no cargo x
int cpessoa[MAXN];	//em que cargo está a pessoa x
int idade[MAXN];	//idade do funcionário
int vis[MAXN], it=0;//visitado e o número da iteração atual


int main(){
	optimize;
	int n, m, in;
	cin>>n>>m>>in;

	for(int i=1; i<=n; i++){
		cin >> idade[i];
		pcargo[i] = i;
		cpessoa[i] = i;
		vis[i] = 0;
	}

	for(int i=0, x, y; i<m; i++)
	{
		cin >> x >> y;
		chefe[y].push_back(x);
	}

	while(in--)
	{
		string c;
		cin >> c;

		if(c == "T")
		{
			int a, b;
			cin >> a >> b;

			swap(cpessoa[a], cpessoa[b]);
			
			pcargo[ cpessoa[b] ] = b;
			pcargo[ cpessoa[a] ] = a;
		}
		else
		{
			it++;
			int p, resp = INF;
			cin >> p;

			stack<int> fila;
			fila.push( cpessoa[p] );

			while(!fila.empty())
			{
				int a = fila.top(); 
				fila.pop();
				vis[a] = it;

				for(auto c : chefe[a])
				{
					resp = min(resp, idade[ pcargo[c] ]);
					if(vis[c] < it) 
						fila.push( c );
				}
			}

			if(resp == INF)
				cout << "*" << endl;
			else
				cout << resp << endl;
		}
	}
	
	return 0;	
}
