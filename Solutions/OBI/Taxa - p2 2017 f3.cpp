#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define INF 0x3f3f3f3f
const int MAXN = 400 + 5;
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2017/f3/taxa/

int arr[MAXN];
int dp[MAXN][MAXN];
int ps[MAXN];

int solve(int l, int r){
	if(l == r) return 0;
	if(~dp[l][r]) return dp[l][r];

	int ans = INF;

	int tot = ps[r+1] - ps[l];
	int sg = 0;

	for(int i=l; i<r; i++)
	{
		sg += arr[i];
		ans = min(ans, solve(l, i) + solve(i+1, r) + max(sg, tot-sg));
	}

	return dp[l][r] = ans;
}

int main(){
	memset(dp, -1, sizeof dp);
	int n; cin >> n;
	double tx; cin >> tx;
	
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
		arr[i+n] = arr[i];
	}
	
	for(int i=0; i<2*n; i++) ps[i+1] = ps[i] + arr[i];

	int ans = INF;

	for(int i=0; i<n; i++)
		ans = min(ans, solve(i, i+n-1));

	cout << fixed << setprecision(2);
	cout << ans*tx << endl;

	return 0;	
}



/*
	Problema de dp. Basicamente consiste em testar todos os casos possíveis, e é isso (note que N <= 200). A maior 
dificuldade mesmo é entender COMO testar tudo, cada caso, especialmente dado que temos um ciclo, e é essa parte que
realmente dificulta.

	A DP do solve() é também bem simples de aplicar na vdd, escolhemos um segmento [l, r] (com o cuidado do ciclo) e
então testamos ir dividindo os terrenos em algum ponto e vemos o resultado mínimo entre todas as possíveis divisões. 
Colocamos a dp pra evitar recalcular a resp de um mesmo segmento várias vezes e pronto! Temos nossa resp!
*/