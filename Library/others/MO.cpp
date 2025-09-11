#include <bits/stdc++.h>
#define ll long long
const int MAXN = 1e5 + 5; 			/*LATEX_IGNORED_LINE*/
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

	sort(queries.begin(), queries.end()); // to use hilbert curves, call sortQueries instead

	int L = 0, R = 0;
	add(0);

	for(auto [l, r, idx] : queries){
		while(l < L) add(--L);
		while(r > R) add(++R);
		while(l > L) remove(L++);
		while(r < R) remove(R--);
		
		ans[idx] = getAnswer();
	}

	return ans;
}

//OPTIONAL
void sortQueries(vector<Query> &qr){ 
	vector<ll> h(qr.size());
	for(int i=0; i<qr.size(); i++) h[i] = hilbert(qr[i].l, qr[i].r);
	sort(qr.begin(), qr.end(), [&](Query&a, Query&b) { return h[a.idx] < h[b.idx]; });
}

inline ll hilbert(int x, int y){ //OPTIONAL
	static int N = 1 << (__builtin_clz(0) - __builtin_clz(MAXN));
	int rx, ry, s; ll d = 0;
	for(s = N/2; s > 0; s /= 2){
		rx = (x & s) > 0, ry = (y & s) > 0;
		d += s * (ll)(s) * ((3 * rx) ^ ry);
		if(ry == 0) { if(rx == 1) x = N-1 - x, y = N-1 - y; swap(x, y); } 
	}
	return d;
}

/*LATEX_DESC_BEGIN***************************
Algoritmo de MO para query em range

**Complexity:** O( (N + Q) * SQRT(N) * F ) | F é a complexidade do Add e Remove

IMPORTANTE! Queries devem ter seus índices (Idx) 0-indexados!

Modifique as operações de Add, Remove e GetAnswer de acordo com o problema.
BLOCK_SZ pode ser alterado para aproximadamente SQRT(MAX_N)
*****************************LATEX_DESC_END*/