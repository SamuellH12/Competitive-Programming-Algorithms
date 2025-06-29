#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;
int ps [MAXN][MAXN];

void calcPS2d(){
	for (int i = 1; i < MAXN; i++) ps[0][i] += ps[0][i - 1];	//inicializo a 1a linha
	for (int i = 1; i < MAXN; i++) ps[i][0] += ps[i - 1][0];	//inicializo a 1a coluna

	for (int i = 1; i < MAXN; i++)
		for (int j = 1; j < MAXN; j++)
			ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
}
int queryPS2d(int xi, int yi, int xf, int yf){ return ps[xf][yf] - ps[xf][yi-1] - ps[xi-1][yf] + ps[xi-1][yi-1]; }

/*LATEX_IGNORED_BEGIN************************
Complexidade:
-> Calcular:  O(N^2)
-> Queries:	  O(1)
***************************LATEX_IGNORED_END*/