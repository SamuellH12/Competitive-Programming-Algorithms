#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2021/f2/poligrama/


int main(){
	int n;		 cin >> n;
	string poli; cin >> poli;
	

	for(int i=1; i*2 <= n; i++)
	{
		if(n % i) continue; //itero pelos divisores de n (ou possíveis palímdromos)

		string raiz = string(poli.begin(), poli.begin()+i);
		sort(ALL(raiz));	//separo a raiz e ordeno

		bool pali = true;
		for(int e=1; e<n/i; e++)
		{
			string a = string(poli.begin() + i*e, poli.begin()+i*(e+1));
			sort(ALL(a));
			if( a != raiz ){ pali = false; break; }	//comparo com todos os outros pedaços de mesmo tamanho (tb ordenados)
		}

		if( pali )	//se todos forem iguais, pronto \(°W°)/
		{
			cout << string(poli.begin(), poli.begin()+i) << endl;
			return 0;
		}
	}

	cout << "*" << endl;
	
	return 0;	
}
