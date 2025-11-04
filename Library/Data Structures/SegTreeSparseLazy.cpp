#include <bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T> struct SparseSeg {
	struct Node	{
		T val = 0, lazy=0; Node *L = NULL, *R = NULL;
		Node(T v = 0) : val(v), L(NULL), R(NULL) {}
	};
	int n; Node* root;
	SparseSeg(int n) : n(n){ root = new Node(NEUTRO); }
	T join(T lv, T rv){ return (lv + rv); }
	const T NEUTRO = 0;

	T query(Node*& no, int l, int r, int a, int b){
		if(!no) no = new Node(NEUTRO); unlazy(no, l, r);
		if(b <  l || r <  a) return NEUTRO;
		if(a <= l && r <= b) return no->val;
		int m=(l+r)/2;
		return join(query(no->L, l, m, a, b), query(no->R, m+1, r, a, b));
	}
	void update(Node*& no, int l, int r, int a, int b, T v){
		if(!no) no = new Node(NEUTRO); unlazy(no, l, r);
		if(b <  l || r <  a) return; 
		if(a <= l && r <= b){ no->lazy += v; return unlazy(no, l, r); }
		int m=(l+r)/2;

		update(no->L,  l,  m, a, b, v);
		update(no->R, m+1, r, a, b, v);

		no->val = join(no->L->val, no->R->val);
	}
	void unlazy(Node* no, int l, int r){ //delete this if not lazy
		if(no->lazy == 0) return;
		if(l != r){
			if(!no->L) no->L = new Node(no->val);
			if(!no->R) no->R = new Node(no->val);
			no->L->lazy += no->lazy;
			no->R->lazy += no->lazy;
		}
		no->val += no->lazy * (r-l+1);
		no->lazy = 0;
	}

	void update(int a, int b, T v){ update(root, 0, n, a, b, v); }
	void update(int pos, T v){ update(root, 0, n, pos, pos, v); }
	T query(int a, int b){ return query(root, 0, n, a, b); }
};

/*LATEX_IGNORED_BEGIN************************
-> Segment Tree Esparsa Lazy
***************************LATEX_IGNORED_END*/