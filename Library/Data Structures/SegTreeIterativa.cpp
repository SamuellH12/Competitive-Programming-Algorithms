#include <bits/stdc++.h>
using namespace std;

template<typename T> struct SegTree {
	int n;
	vector<T> seg;
	T join(T&l, T&r){ return l + r; }
	
	SegTree(int n) : n(n), seg(2*n) {}
	SegTree(){}
	void init(vector<T>&base){
		n = base.size();
		seg.resize(2*n);
		for(int i=0; i<n; i++) seg[i+n] = base[i];
		for(int i=n-1; i>0; i--) seg[i] = join(seg[i*2], seg[i*2+1]);
	}

	T query(int l, int r){ //[L, R] // [0, n-1]
		T lp = 0, rp = 0; //NEUTRO
		for(l+=n, r+=n+1; l<r; l/=2, r/=2){
			if(l&1) lp = join(lp, seg[l++]);
			if(r&1) rp = join(seg[--r], rp);
		}
		return join(lp, rp);
	}

	void update(int i, T v){ // Set Value seg[i+=n] = v // change to += v to sum
		for(seg[i+=n] = v; i/=2;) seg[i] = join(seg[i*2], seg[i*2+1]); 
	}
};