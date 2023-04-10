#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

struct BIT2D {
	int bit[MAXN][MAXN];

	void update(int X, int Y, int val)
	{
		for(int x = X; x < MAXN; x += x&(-x))
			for(int y = Y; y < MAXN; y += y&(-y))
				bit[x][y] += val;
	}

	int query(int X, int Y)
	{
		int sum = 0;

		for(int x = X; x > 0; x -= x&(-x))
			for(int y = Y; y > 0; y -= y&(-y))
				sum += bit[x][y];
			
		return sum;
	}

	int queryArea(int xi, int yi, int xf, int yf){
		return query(xf, yf) - query(xf, yi-1) - query(xi-1, yf) + query(xi-1, yi-1);
	}

	void init(){
		memset(bit, 0, sizeof bit);
	}

} Bit;


int main(){
	cout << "Binary Indexed Tree 2D - Fenwick Tree 2D" << endl;
	return 0;	
}

/*
Syntax:

Bit.init();				//Seta tudo como 0
Bit.update(x, y, v);	//Adiciona +v na posição {x, y} da BIT
Bit.query(x, y);		//Retorna o somatorio do retangulo de inicio {1, 1} e fim {x, y}
Bit.queryArea(xi, yi, xf, yf);	//Retorna o somatorio do retangulo de inicio {xi, yi} e fim {xf, yf}

Query:  O(log NM)
Update: O(log NM)

*Build: O(NM log NM)
Para consultas estáticas, sem update, o melhor é usar uma Prefix Sum 2D

-> N: Numero de colunas
-> M: Numero de linhas
*/

