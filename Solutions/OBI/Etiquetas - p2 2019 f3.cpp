#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 10010
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2019/f3/etiquetas/

int n, k, c;
int fita[MAXN];
int memo[MAXN][MAXN];


int main(){
	optimize;
	cin >> n >> k >> c;

	fita[0] = 0;
	for(int i=1; i<=n; i++){
		cin >> fita[i];
		fita[i] += fita[i-1];
	}
	
	
	// +==== PD iterativa (recursiva é muito lenta) =====+

	memo[0][0] = 0;
	for(int i=1; i<=k; i++) 
		memo[0][i] = INF;


	for(int i=1; i<=n; i++){
		for(int j=0; j<=k; j++)
		{
			//nao usa etiqueta
			memo[i][j] = memo[i-1][j];

			//usa a etiqueta
			if(j>0 && i >= c)
			memo[i][j] = min(memo[i][j],  (memo[i-c][j-1] + fita[i] - fita[i-c]) );
		}
	}


	cout << fita[n] - memo[n][k] << endl;
	
	return 0;	
}

/*
(-_-) Só passa com pd iterativa...
*/