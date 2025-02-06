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

  

int main(){
	
	ll rc, xc, yc, rf, xf, yf;

	while(cin>> rc>>xc>>yc >> rf>>xf>>yf){
		bool vivo = false;

		if(rc < rf){ cout<<"MORTO"<<endl; continue;}

		int dist = sqrt( (xc - xf) * (xc - xf) +  (yc - yf) * (yc - yf) );

		if( dist + rf <  rc ) vivo = true;
		if( dist + rf <= rc && (xc == xf || yc == yf)) vivo = true;

		cout<<(vivo ? "RICO" : "MORTO")<<endl;
	}

	return 0;	
}



/************************************************************

*Ok, o que aprendemos aqui? Para verificar se um círculo esta
dentro do outro, podemos pegar a distancia entre seus dois 
centros e verificar se a distancia entre os dois centros mais
o raio do segundo círculo são menores ou iguais ao raio do
primeiro círculo. Fica também a observação de que só pode ser 
igual se estiver no mesmo x ou y, "por quê?", você me 
pergunta, e eu lhe respondo: Não tenho a menor ideia!!! Não 
entendi o porquê disto, talvez alguma desatenção minha no 
cálculo, talvez não, talvez seja por algum conceito 
matemático que eu não conheço, talvez não também, mas fica a
lembrança, quando for fazer de novo, lembre-se disto!

************************************************************/