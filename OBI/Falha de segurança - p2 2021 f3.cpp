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
//https://olimpiada.ic.unicamp.br/pratique/p2/2021/f3/falha

int main()
{
	int n; cin >> n;
	string aux;
	vector<string> senha (n);
	map<string, int> mapa;

	for(int i=0; i<n; i++){
		cin >> aux;
		senha[i] = aux;

		//armazeno todas as possíveis sub senhas da minha string num set (pra não contar as repetições)
		set<string> sub;
		for(int i=1; i<=aux.size(); i++)
			for(int j=0; j+i<=aux.size(); j++)
				sub.insert( string(aux.begin()+j, aux.begin()+j+i) );
		
		//e guardo num map as subsenhas possíveis com a qtd de ocorrencias
		for(auto x : sub) 
			mapa[x]++;
	}

	int resp = 0;
	for(auto x : senha)	
		resp += mapa[x] - 1;

	cout << resp << endl;

	return 0;
}