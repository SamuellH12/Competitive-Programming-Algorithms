#include <bits/stdc++.h>
using namespace std;

template<typename T> struct SegTree {
	int n, h;
	vector<T> seg, lzy;
	vector<int> sz;
	T join(T&l, T&r){ return l + r; }

	void init(int _n){
		n = _n;
		h = 32 - __builtin_clz(n);
		seg.resize(2*n);
		lzy.resize(n);
		sz.resize(2*n, 1);
		for(int i=n-1; i; i--) sz[i] = sz[i*2] + sz[i*2+1];
		// for(int i=0; i<n; i++) seg[i+n] = base[i];
		// for(int i=n-1; i; i--) seg[i] = join(seg[i*2], seg[i*2+1]);
	}

	void apply(int p, T v){
		seg[p] += v * sz[p];
		if(p < n) lzy[p] += v;
	}
	void push(int p){
		for(int s=h, i=p>>s; s; s--, i=p>>s)
			if(lzy[i] != 0) { 
				apply(i*2,   lzy[i]);
				apply(i*2+1, lzy[i]);
				lzy[i] = 0; //NEUTRO
			}
	}
	void build(int p) {
		for(p/=2; p; p/= 2){
			seg[p] = join(seg[p*2], seg[p*2+1]);
			if(lzy[p] != 0) seg[p] += lzy[p] * sz[p];
		}
	}

	T query(int l, int r){ //[L, R] & [0, n-1]
		l+=n, r+=n+1; 
		push(l); push(r-1);
		
		T ans = 0; //NEUTRO
		for(; l<r; l/=2, r/=2){
			if(l&1) ans = join(seg[l++], ans);
			if(r&1) ans = join(ans, seg[--r]);
		}
		return ans;
	}

	void update(int l, int r, T v){
		l+=n, r+=n+1; 
		push(l); push(r-1);
		
		int l0 = l, r0 = r;
		for(; l<r; l/=2, r/=2){
			if(l&1) apply(l++, v);
			if(r&1) apply(--r, v);
		}
		build(l0); build(r0-1);
	}
};