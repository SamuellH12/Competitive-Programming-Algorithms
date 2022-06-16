#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;



int main(){
	
	int n, resp = 0; 
	cin>>n;
	int h[n+1], pre[n+1], suf[n+1]; 
	
	pre[0] = 0; 
	for(int i=1; i<=n; i++)
	{
		cin >> h[i];
		pre[i] = max(pre[i-1], h[i]); //Calcula maior prefixo
	}


	suf[n] = h[n];
	for(int i=n-1; i>0; i--)
		suf[i] = max(suf[i+1], h[i]); //calcula maior sufixo
	
	for(int i=1; i<=n; i++)
		if( h[i] < suf[i] && h[i] < pre[i]  ) resp++;
	//Se estiver entre dois pontos mais altos (menor que o suf e pre), enche, então resp++

	cout << resp << endl;
	
	return 0;	
}


/*
Explicação da resposta:

os arrays PRE(FIXO) e SUF(IXO) guardam respectivamente
o maior valor que vem antes de uma posição e o maior
valor que vem depois dessa posição

Assim, se hi é menor que o menor que o maior valor a sua 
esquerda e menor que o maior valor sua direita, então ele
está inundado, isso pois, caso o contrário, ele seria uma
"ilha", ou uma "parede de barragem", estando portanto 
acima do nível da água.

Palavras-chave: PREFIXO & SUFIXO

*/