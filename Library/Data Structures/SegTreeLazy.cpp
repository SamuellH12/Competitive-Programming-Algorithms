#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int seg[4*MAXN];
int lazy[4*MAXN];

void unlazy(int no, int l, int r){
	if(lazy[no] == 0) return;

	int m=(l+r)/2, e=no*2, d=no*2+1;

	seg[no] += (r-l+1) * lazy[no];

	if(l != r){
		lazy[e] += lazy[no];
		lazy[d] += lazy[no];
	}

	lazy[no] = 0;
}

int query(int no, int l, int r, int a, int b){
	unlazy(no, l, r);
	if(b <  l || r <  a) return 0;
	if(a <= l && r <= b) return seg[no];
	
	int m=(l+r)/2, e=no*2, d=no*2+1;

	return query(e, l, m, a, b) + query(d, m+1, r, a, b);
} 

void update(int no, int l, int r, int a, int b, int v){
	unlazy(no, l, r);
	if(b <  l || r <  a) return;
	if(a <= l && r <= b)
	{
		lazy[no]+= v;
		unlazy(no, l, r);
		return;
	}

	int m=(l+r)/2, e=no*2, d=no*2+1;

	update(e, l,   m, a, b, v);
	update(d, m+1, r, a, b, v);

	seg[no] = seg[e] + seg[d];
}

void build(int no, int l, int r, vector<int> &lista){
	if(l == r){ seg[no] = lista[l-1]; return; }

	int m=(l+r)/2, e=no*2, d=no*2+1;

	build(e, l,   m, lista);
	build(d, m+1, r, lista);
	
	seg[no] = seg[e] + seg[d];
}

/******************************************************
-> Segment Tree - Lazy Propagation com:
	- Query em Range
	- Update em Range
	
build (1, 1, n, lista);
query (1, 1, n, a, b);
update(1, 1, n, a, b, x);

|   n    | o tamanho máximo da lista
| [a, b] | o intervalo da busca ou update
|   x    | o novo valor a ser somada no intervalo [a, b]
| lista  | o array de elementos originais

Build:  O(N)
Query:  O(log N)
Update: O(log N)
Unlazy: O(1)
*******************************************************/