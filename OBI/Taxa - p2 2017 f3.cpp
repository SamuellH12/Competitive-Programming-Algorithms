#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 210
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2017/f3/taxa/

int n; 
int lista[MAXN], sum[MAXN][MAXN], memo[MAXN][MAXN];


int menos(int x){ return ( (x-1+n)%n == 0 ? n : (x-1+n)%n); }

int get_sum(int i, int j)
{
	if(sum[i][j]) return sum[i][j];
	if(i == j) return sum[i][j] = lista[i];
	return sum[i][j] = lista[j] + get_sum(i, menos(j));
}



int solve(int l, int r)
{
	if(memo[l][r]) return memo[l][r];
	if(l==r) return 0;

	int mn = INF;

	for(int i=r; i!=l; i = menos(i) )
	{
		int corte = max(get_sum(l, menos(i)), get_sum(i, r));
		mn = min(mn, corte + solve(l, menos(i)) + solve(i, r) );
	}

	return memo[l][r] = mn;
}



int main(){
	double f;
	cin >> n >> f;

	for(int i=1; i<=n; i++)
	{
		cin >> lista[i];
	}
	
	int resp = INF;
	for(int i=1; i<=n; i++)
		resp = min(resp, solve(i, menos(i)));

	cout << fixed << setprecision(2) << f * resp << endl;
	
	return 0;	
}


/*
	Problema de dp. Basicamente consiste em testar todos os casos possíveis, e é isso (note que N <= 200). A maior 
dificuldade mesmo é entender COMO testar tudo, cada caso, especialmente dado que temos um ciclo, e é essa parte que
realmente dificulta. Para contornar essa dificuldade do ciclo se usa a função menos(i), que vai garantir que não 
possamos manter o ciclo 1 2 3 N 1 2 3 N, e a função de soma que nos dá a soma de um segmento (inicialmente tentei 
com prefix sum, mas ficava meio chato de fazer as consultas, essa ideia de uma dp fica muito boa).

	A DP do solve() é também bem simples de aplicar na vdd, escolhemos um segmento [l, r] (com o cuidado do ciclo) e
então testamos ir dividindo os terrenos em algum ponto e vemos o resultado mínimo entre todas as possíveis divisões. 
Colocamos a dp pra evitar recalcular a resp de um mesmo segmento várias vezes e voilà! Temos nossa resp!
*/