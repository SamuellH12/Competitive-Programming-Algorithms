#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 2010
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;
int n, m;
vi ruas [MAXN];
  
bool dfs(int origem){

	stack<int> pilha;
	bool visitado[MAXN];
	memset(visitado, false, sizeof visitado);
	pilha.push(origem);

	
	while(!pilha.empty())
	{
		int atual = pilha.top(); pilha.pop();
		
		if(visitado[atual]) continue;
		   visitado[atual] = true;
		//cout<<origem<<"->"<<atual<<endl;
		for(auto proximo : ruas[atual])
			pilha.push(proximo);
	}

	for(int i=1; i<=n; i++){
		//cout<<i<<"-"<<visitado[i]<<endl;
		if(!visitado[i])
			return false;
		}

	return true;
}

int main(){
	optimize;

	while(cin>>n>>m && (n+m)){
		
		for(int i=1; i<=n; i++)
			ruas[i].clear();

		for(int i=0; i<m; i++){
			int u, v, p;
			cin>>u>>v>>p;
			ruas[u].push_back(v); 
			if(p==2) ruas[v].push_back(u);
		}

		bool chave = true;
		for(int i=1; i<=n; i++)
			if(!dfs(i))
			{
				chave = false;
				break;
			}
		

		cout<< (chave == true ? 1 : 0) <<endl;

	}



	return 0;	
}
