#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int seg[4*MAXN];


int query(int no, int l, int r, int a, int b){
	if(b <  l || r <  a ) return 0;
	if(a <= l && r <= b) return seg[no];

	int m=(l+r)/2, e=no*2, d=no*2+1;

	return query(e, l, m, a, b) + query(d, m+1, r, a, b);
}

void update(int no, int l, int r, int pos, int v){
	if(pos < l || r < pos) return;
	if(l == r){seg[no] = v; return; }

	int m=(l+r)/2, e=no*2, d=no*2+1;

	update(e, l,   m, pos, v);
	update(d, m+1, r, pos, v);

	seg[no] = seg[e] + seg[d];
}

void build(int no, int l, int r, vector<int> &lista){
	if(l == r){ seg[no] = lista[l-1]; return; }

	int m=(l+r)>>1, e=no*2, d=no*2+1;

	build(e, l,   m, lista);
	build(d, m+1, r, lista);
	
	seg[no] = seg[e] + seg[d];
}


int main()
{
	cout << "Segment Tree" << endl;
	return 0;
}

/******************************************************

-> Segment Tree com:
	- Query em Range
	- Update em Ponto

-> Chamadas padrão:
	build(1, 1, n, lista);
	query(1, 1, n, a, b);
	update(1, 1, n, i, x);

-> Em que:
|   n    | o tamanho máximo da lista
| [a, b] | o intervalo da busca 
|   i    | a posição a ser modificada
|   x    | o novo valor da posição i
| lista  | o array de elementos originais


Build:  O(N)
Query:  O(log N)
Update: O(log N)

*******************************************************/