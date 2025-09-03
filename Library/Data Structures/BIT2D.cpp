#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

struct BIT2D {
	int bit[MAXN][MAXN];

	void update(int X, int Y, int val){
		for(int x = X; x < MAXN; x += x&(-x))
			for(int y = Y; y < MAXN; y += y&(-y))
				bit[x][y] += val;
	}

	int query(int X, int Y){
		int sum = 0;
		for(int x = X; x > 0; x -= x&(-x))
			for(int y = Y; y > 0; y -= y&(-y))
				sum += bit[x][y];
		return sum;
	}

	void updateArea(int xi, int yi, int xf, int yf, int val); //Same of BIT2DSparse
	int queryArea(int xi, int yi, int xf, int yf); //Same of BIT2DSparse
};

/*LATEX_DESC_BEGIN***************************
**Complexity:** O(Log^2 N)
Bit.update(x, y, v);	//Adiciona +v na posição {x, y} da BIT
Bit.query(x, y);		//Retorna o somatorio do retangulo de inicio {1, 1} e fim {x, y}
Bit.queryArea(xi, yi, xf, yf);     //Retorna o somatorio do retangulo de inicio {xi, yi} e fim {xf, yf}
Bit.updateArea(xi, yi, xf, yf, v); //adiciona +v no retangulo de inicio {xi, yi} e fim {xf, yf}

IMPORTANTE! UpdateArea NÃO atualiza o valor de todas as células no retângulo!!! Deve ser usado para Color Update
IMPORTANTE! Use query(x, y) Para acessar o valor da posição (x, y) quando estiver usando UpdateArea
IMPORTANTE! Use queryArea(x, y, x, y) Para acessar o valor da posição (x, y) quando estiver usando Update Padrão  
*****************************LATEX_DESC_END*/