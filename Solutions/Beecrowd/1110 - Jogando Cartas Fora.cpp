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

//https://www.beecrowd.com.br/judge/pt/problems/view/1110

int main(){

	int n;

	while( cin>>n && n != 0 )
	{
		cout << "Discarded cards: ";

		bool prim = true;
		queue<int> fila;

		for(int i=1; i<=n; i++)
			fila.push(i);
		
		while( fila.size() > 1)
		{
			//imprimir a carta removida
			if( !prim ) cout << ", ";
			else prim = false;
			cout << fila.front();

			//removemos o elemento de cima
			fila.pop();

			//colocamos o segundo pro fim da fila (baixo)
			int temp = fila.front();
			fila.pop();
			fila.push(temp);
		}

		cout << endl << "Remaining card: " << fila.front() << endl;

	}

	
	
	return 0;	
}
