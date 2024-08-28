#include <bits/stdc++.h>
using namespace std;

const int BLOCK_SZ = 700;

struct Query{
	int l, r, idx;

	Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
	
	bool operator < (Query q) const {
		if(l / BLOCK_SZ != q.l / BLOCK_SZ) return l < q.l;
		return (l / BLOCK_SZ &1) ? ( r < q.r ) : (r > q.r );
	}
};

void add(int idx);
void remove(int idx);
int getAnswer();

vector<int> MO(vector<Query> &queries){
	vector<int> ans(queries.size());

	sort(queries.begin(), queries.end());

	int L = 0, R = 0;
	add(0);

	for(auto [l, r, idx] : queries)
	{
		while(l < L) add(--L);
		while(r > R) add(++R);
		while(l > L) remove(L++);
		while(r < R) remove(R--);
		
		ans[idx] = getAnswer();
	}

	return ans;
}

/**************************************
Algoritmo de MO para query em range

Complexity: O( (N + Q) * SQRT(N) * F ) | F é a complexidade do Add e Remove

IMPORTANTE! Queries devem ter seus índices (Idx) 0-indexados!

Modifique as operações de Add, Remove e GetAnswer de acordo com o problema.
BLOCK_SZ pode ser alterado para aproximadamente SQRT(MAX_N)
***************************************/