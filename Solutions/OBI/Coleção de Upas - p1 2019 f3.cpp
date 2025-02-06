#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 100010
#define INF  1001
#define debug cout<<"ate aqui ok\n"
using namespace std;


int main(){
	int n, m;

	cin>>n>>m;

	vi   nc[n+1];
	bool NC[n+1]; memset(NC, false, sizeof NC);

	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		nc[u].push_back(v);
		nc[v].push_back(u);
	}

	vi resp;
	
	for(int i=n; i>0; i--){
		if(!NC[i]){
			resp.push_back(i);
			for(auto a : nc[i]) NC[a] = true;
		}
	}


	cout<<resp.size()<<endl;

	for(int e = resp.size() - 1; e >= 0; e--)
		cout<<resp[e]<<" ";
	cout<<endl;

	return 0;	
}



// propriedade intressante:( 2^n ) > ( 2^n-1 + 2^n-2 + ... + 2^1)
// isso significa que a upa de maior valor sempre terá mais valor que todas as demais combinadas
// portanto, a solução implica somente em pegar sempre a maior e as que for possível combinar a ela