#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int ps [MAXN][MAXN];

void calcPS2d(){
	for (int i = 1; i < MAXN; i++) ps[0][i] += ps[0][i - 1];	//inicializo a primeira linha
	for (int i = 1; i < MAXN; i++) ps[i][0] += ps[i - 1][0];	//inicializo a primeira coluna

	for (int i = 1; i < MAXN; i++)
		for (int j = 1; j < MAXN; j++)
			ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
}

inline int queryPS2d(int xi, int yi, int xf, int yf){ return ps[xf][yf] - ps[xf][yi-1] - ps[xi-1][yf] + ps[xi-1][yi-1]; }
//Para consultas 0-indexado adicionar um IF para verificar esse caso

int main(){
	memset(ps, 0, sizeof ps);
	
	//Inicializo a matriz com os valores
	ps[2][3] = 9;
	ps[5][8] = 4;
	ps[3][4] = 5;

	//Calculo a Prefix Sum
	calcPS2d();

	//Faço consulta da soma do retângulo de cantos {xi, yi} e {xf, yf};
	cout << queryPS2d(1, 1, 10, 10) << endl;
	
	return 0;	
}

/**************
Complexidade:

-> Calcular:  O(N^2)
-> Queries:	  O(1)

*Se forem necessários updates, utilizar BIT2D

***************/