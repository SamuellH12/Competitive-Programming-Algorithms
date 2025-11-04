#include <bits/stdc++.h>
using namespace std;

template<typename T> struct SegTree {
	vector<T> seg;
	vector<T> lazy;
	int N;
	T NEUTRO = 0;
	SegTree(int n) : N(n){ seg.assign(4*N, NEUTRO), lazy.assign(4*N, NEUTRO); }
	SegTree(vector<T> &lista) : N(lista.size()){ 
		seg.assign(4*N), lazy.assign(4*N, NEUTRO); 
		build(1, 0, N-1, lista); 
	}
	T join(T lv, T rv){ return lv + rv; }
	void unlazy(int no, int l, int r){
		if(lazy[no] == NEUTRO) return;
		int m=(l+r)/2, e=no*2, d=e+1;

		seg[no] += (r-l+1) * lazy[no]; /// Range Sum

		if(l != r) lazy[e] += lazy[no], lazy[d] += lazy[no];
		lazy[no] = NEUTRO;
	}

	T query(int no, int l, int r, int a, int b){
		unlazy(no, l, r);
		if(b <  l || r <  a) return NEUTRO;
		if(a <= l && r <= b) return seg[no];
		int m=(l+r)/2, e=no*2, d=e+1;

		return join(query(e, l, m, a, b), query(d, m+1, r, a, b));
	}

	void update(int no, int l, int r, int a, int b, T v){
		unlazy(no, l, r);
		if(b <  l || r <  a) return;
		if(a <= l && r <= b){
			lazy[no] = join(lazy[no], v); // cumulative?
			return unlazy(no, l, r);
		}
		int m=(l+r)/2, e=no*2, d=e+1;

		update(e, l,   m, a, b, v);
		update(d, m+1, r, a, b, v);

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
	void update(int l, int r, T v){ update(1, 0, N-1, l, r, v); }
};


/*LATEX_DESC_BEGIN***************************
-> **Segment Tree - Lazy Propagation** com:
	- Query em Range
	- Update em Range
	- Closed interval & 0-indexed: [L, R] & [0, N-1]
Build:  O(N)
Query:  O(log N) | seg.query(l, r);
Update: O(log N) | seg.update(l, r, v);
Unlazy: O(1)
**Update Join, NEUTRO, Update and Unlazy if needed**
*****************************LATEX_DESC_END*/