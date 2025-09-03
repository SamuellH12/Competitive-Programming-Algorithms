#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define upper(v, x) (upper_bound(begin(v), end(v), x) - begin(v)) 

struct BIT2D {
	vector<int> ord;
	vector<vector<int>> bit, coord;

	BIT2D(vector<pii> pts){
		sort(begin(pts), end(pts));
		
		for(auto [x, y] : pts)
			if(ord.empty() || x != ord.back())
				ord.push_back(x);

		bit.resize(ord.size() + 1);
		coord.resize(ord.size() + 1);

		sort(begin(pts), end(pts), [&](pii &a, pii &b){ return a.second < b.second; });

		for(auto [x, y] : pts)
			for(int i=upper(ord, x); i < bit.size(); i += i&-i)
				if(coord[i].empty() || coord[i].back() != y)
					coord[i].push_back(y);

		for(int i=0; i<bit.size(); i++) bit[i].assign(coord[i].size()+1, 0);
	}

	void update(int X, int Y, int v){
		for(int i = upper(ord, X); i<bit.size(); i += i&-i)
			for(int j = upper(coord[i], Y); j < bit[i].size(); j += j&-j)
				bit[i][j] += v;
	}

	int query(int X, int Y){
		int sum = 0;
		for(int i = upper(ord, X); i > 0; i -= i&-i)
			for(int j = upper(coord[i], Y); j > 0; j -= j&-j)
				sum += bit[i][j];
		return sum;
	}

	void updateArea(int xi, int yi, int xf, int yf, int val){
		update(xi,   yi,    val); 
		update(xf+1, yi,   -val); 
		update(xi,   yf+1, -val);
		update(xf+1, yf+1,  val);
	}

	int queryArea(int xi, int yi, int xf, int yf){
		return query(xf, yf) - query(xf, yi-1) - query(xi-1, yf) + query(xi-1, yi-1);
	}
};

/*LATEX_DESC_BEGIN***************************
Sparse Binary Indexed Tree 2D

Recebe o conjunto de pontos que serão usados para fazer os updates e as queries e cria uma BIT 2D esparsa que independe do "tamanho do grid".

**Build:** O(N Log N) (N -> Quantidade de Pontos)
**Query/Update:** O(Log N) 
IMPORTANTE! **Offline!**

BIT2D(pts);   // pts -> vecotor<pii> com todos os pontos em que serão feitas queries ou updates

Credits: TFG (TFG50 on Git: https://github.com/tfg50/Competitive-Programming/blob/master/Biblioteca/Data%20Structures/Bit2D.cpp)
*****************************LATEX_DESC_END*/