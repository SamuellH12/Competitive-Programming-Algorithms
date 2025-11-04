#include <bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T> struct SparseSeg {
	struct Node	{
		T val = 0; Node *L = NULL, *R = NULL;
		Node(T v = 0) : val(v), L(NULL), R(NULL) {}
	};
	int n; Node* root;
	SparseSeg(int n) : n(n){ root = new Node(NEUTRO); }
	T join(T lv, T rv){ return max(lv, rv); }
	const T NEUTRO = 0;

	T query(Node*& no, int l, int r, int a, int b){
		if(b <  l || r <  a || no == NULL) return NEUTRO;
		if(a <= l && r <= b) return no->val;
		int m=(l+r)/2;
		return join(query(no->L, l, m, a, b), query(no->R, m+1, r, a, b));
	}
	void update(Node*& no, int l, int r, int pos, T v){
		if(!no) no = new Node(NEUTRO);
		if(pos < l || r < pos) return;
		if(l == r) return (void)(no->val = v);
		int m=(l+r)/2;

		update(no->L,  l,  m, pos, v);
		update(no->R, m+1, r, pos, v);

		no->val = join(no->L->val, no->R->val);
	}

	void update(int pos, T v){ update(root, 0, n, pos, v); }
	T query(int a, int b){ return query(root, 0, n, a, b); }
};

/*LATEX_IGNORED_BEGIN************************
-> Segment Tree Esparsa
***************************LATEX_IGNORED_END*/