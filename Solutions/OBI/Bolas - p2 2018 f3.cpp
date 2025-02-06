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
//https://olimpiada.ic.unicamp.br/pratique/p2/2018/f3/bolas/

int main(){

	int lista[8];

	for(int i=0; i<8; i++)
		cin >> lista[i];

	sort(lista, lista+8);

	int cont = 0, last = -1;
	for(int i=0; i<8; i++)
	{
		if(lista[i] != last){ cont = 1; last = lista[i];}
		else cont++;

		if(cont > 4)
		{
			cout << "N" << endl;
			return 0;
		}
	}


	cout << "S" << endl;

	return 0;	
}

//preceito: se houver 4 ou menos bolas de um mesmo tipo há como arranjá-las sem deixá-las lado a lado;