#include <bits/stdc++.h>
using namespace std;

template<typename T> struct SegTree {
	int n;
	vector<T> seg;
	T join(T&l, T&r){ return l + r; }

	void init(vector<T>&base){
		n = base.size();
		seg.resize(2*n);
		for(int i=0; i<n; i++) seg[i+n] = base[i];
		for(int i=n-1; i; i--) seg[i] = join(seg[i*2], seg[i*2+1]);
	}

	T query(int l, int r){ //[L, R] & [0, n-1]
		T ans = 0; //NEUTRO	//if order matters, change to l_ans, r_ans
		for(l+=n, r+=n+1; l<r; l/=2, r/=2){
			if(l&1) ans = join(ans, seg[l++]);
			if(r&1) ans = join(seg[--r], ans);
		}
		return ans;
	}

	void update(int i, T v){
		for(seg[i+=n] = v; i/=2;) seg[i] = join(seg[i*2], seg[i*2+1]);
	}
};