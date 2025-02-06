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

//https://olimpiada.ic.unicamp.br/pratique/p2/2017/f2/mapa/

int main(){
	int L, C;
	cin >> L >> C;

	string mapa [L];
	int li, ci;

	for(int i=0; i<L; i++)
	{
		cin >> mapa[i];

		for(int e=0; e<C; e++)
			if( mapa[i][e] == 'o' )
			{
				li = i;
				ci = e;
			}
	}

	stack<pii> pilha;
	pilha.push({li, ci});

	while( !pilha.empty() )
	{
		
		int l = pilha.top().first;
		int c = pilha.top().second;
		pilha.pop();

		mapa[l][c] = '.';

		bool fim = true;

		if( l > 0 && mapa[l-1][c] == 'H' ){
			pilha.push({l-1, c});
			fim = false;
		}

		if( l<L-1 && mapa[l+1][c] == 'H' ){
			pilha.push({l+1, c});
			fim = false;
		}

		if( c > 0 && mapa[l][c-1] == 'H' ){
			pilha.push({l, c-1});
			fim = false;
		}

		if( c<C-1 && mapa[l][c+1] == 'H' ){
			pilha.push({l, c+1});
			fim = false;
		}

		if(fim){
			cout << l+1 << " " << c+1 << endl;
			break;
		}

	}
	
	
	return 0;	
}
