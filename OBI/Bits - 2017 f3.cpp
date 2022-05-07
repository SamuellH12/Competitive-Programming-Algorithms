#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p1/2017/f3/bits/

int N, K;
int dp[1001][1001];
bool memo[1001][1001];


int incrementa(int n, int q){
	if(memo[n][q]) return dp[n][q];
	if(n==0) return 1;
	int resp = 0;

	//pra 0
	resp += incrementa(n-1, K);

	//pra 1
	if(q>1) resp += incrementa(n-1, q-1);
	
	memo[n][q] = true;
	return dp[n][q] = resp % 1000000007;
}


int main(){
	cin>>N>>K;

	cout<<incrementa(N, K)<<endl;

	return 0;	
}

/****************************************************************
Anotações importantes:

- Para números absurdamente grandes se pode usar  __int128_t
  ele vai até 10^38 aproximadamente

- O resto da divisão por um número grande é correspondente a
  soma dos restos da divisão por suas partes menores, o que pode
  evitar a necessidade de números absurdamente grandes

******************************************************************/