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
*****************************LATEX_DESC_END*/