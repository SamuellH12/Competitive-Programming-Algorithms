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
//https://olimpiada.ic.unicamp.br/pratique/p2/2020/f3/jogo/

int matriz[7][7], l, c, p;
pii dir [4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<pii> brancas;

inline bool vago(int x, int y, int t)
{
	if(x<=0 || y <=0 || x > l || y > c || matriz[x][y] == t) return false;
	return true;
}

inline bool valido(int x, int y)
{
	for(auto d : dir)
		if( matriz[x+d.first][y+d.second] == 2 ) 
		 	return false;
	return true;
}

inline void calcB(int x, int y)
{
	for(auto d : dir)
		if(vago(x+d.first, y+d.second, 1))
			brancas.push_back({x+d.first, y+d.second});
}


int jogador(int i)
{
	if(i == brancas.size()) return 0;

	pii peca = brancas[i];

	//não pega
	int resp = jogador(i+1);

	if(vago(peca.first, peca.second, 2) && valido(peca.first, peca.second)) 	 
	{
		matriz[peca.first][peca.second] = 2; //marca
		resp = max(jogador(i+1) + 1, resp);	 //pega
		matriz[peca.first][peca.second] = 0; //desmarca
	}

	return resp;
}


int main(){
	cin >> l >> c >> p;

	vector<pii> pretas (p);

	for(int i=0, x, y; i<p; i++)
	{
		cin >> x>> y;
		pretas[i] = {x, y};
		matriz[x][y] = 1;
	}

	for(auto peca : pretas) 
		calcB(peca.first, peca.second); //acha todas as posições possíveis para 

	cout << jogador(0) << endl;
	
	return 0;	
}


/*
	A grande sacada dessa questão é pensar nela como problema da mochila, e não como problema de matriz.
A matriz aqui é usada mais como uma memória de quais já foram pegas do que qualquer outra coisa.
Além disso, problema da mochila aqui, mesmo sem pd, é muito rápido, pois não existem mais que 36 possíveis peças brancas. :)
*/