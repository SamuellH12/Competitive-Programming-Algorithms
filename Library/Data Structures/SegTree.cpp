#include <bits/stdc++.h>
using namespace std;

template<typename T> struct SegTree {
	vector<T> seg;
	int N;
	T NEUTRO = 0;
	SegTree(int n) : N(n) { seg.assign(4*n, NEUTRO); }
	SegTree(vector<T> &lista) : N(lista.size()) { seg.assign(4*N); build(1, 0, N-1, lista); }
	T join(T lv, T rv){ return lv + rv; }
		
	T query(int no, int l, int r, int a, int b){
		if(b <  l || r <  a) return NEUTRO;
		if(a <= l && r <= b) return seg[no];
		int m=(l+r)/2, e=no*2, d=e+1;
		
		return join(query(e, l, m, a, b), query(d, m+1, r, a, b));
	}
	void update(int no, int l, int r, int pos, T v){
		if(pos < l || r < pos) return;
		if(l == r){ seg[no] = v; return; }  // set value -> change to += if sum
		int m=(l+r)/2, e=no*2, d=e+1;

		update(e, l,   m, pos, v);
		update(d, m+1, r, pos, v);

		seg[no] = join(seg[e], seg[d]);
	}
	void build(int no, int l, int r, vector<T> &lista){
		if(l == r){ seg[no] = lista[l]; return; }
		int m=(l+r)/2, e=no*2, d=e+1;
		
		build(e, l,   m, lista);
		build(d, m+1, r, lista);
		
		seg[no] = join(seg[e], seg[d]);
	}

	T query(int ls, int rs){ return query (1, 0, N-1, ls, rs); }
	void update(int pos, T v){      update(1, 0, N-1, pos, v); }
};

/*LATEX_IGNORED_BEGIN************************
-> Segment Tree com:
	- Query em Range
	- Update em Ponto
	- Closed interval & 0-indexed: [L, R] & [0, N-1]
Build:  O(N)
Query:  O(log N) | seg.query(l, r);
Update: O(log N) | seg.update(i, v);
**Update Join, NEUTRO and Update if needed**
***************************LATEX_IGNORED_END*/