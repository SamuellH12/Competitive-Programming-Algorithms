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

//novo conceito: soma de prefixos

int main(){
	optimize;
	int n, o;

	cin>>n>>o;

	int cima[n+1], baixo[n+1];
	int virado[n+1];

	for(int i=1; i<=n; i++) cin>>cima[i];

	for(int i=1; i<=n; i++) cin>>baixo[i];
	
	memset(virado, 0, sizeof virado);

	while(o--)
	{
		int a, b;
		cin>>a>>b;

		virado[a]++;
		virado[b+1]--;
	}

	for(int i=1; i<=n; i++)
		virado[i] += virado[i-1];

	for(int i=1; i<=n; i++)
		cout<< (virado[i]%2 ? baixo[i] : cima[i])<<" "; 
		cout<<endl;

	return 0;	
}


/*
como funciona:
partindo do conceito da soma de prefixos, temos
um array de operações feitas, que, inicialmente
está zerado

|0|0|0|0|0|0|0|0|0|0|

em seguida eu faço uma operação de virar as cartas
de 2 a 6, nisso aumento 2 e diminuo 7, que não será
alterado, assim seu valor será restituido na soma de prefixos

|0|1|0|0|0|0|0|-1|0|0|

quando for realizada a soma, teremos:

|0|1|1|1|1|1|1|0|0|0|

Isso ainda pode ser feito com muitas outras trocas
no momento da soma elas se corrigirão e então os 
números pares representam cartas pra cima e ímpares
cartas para baixo.

*/