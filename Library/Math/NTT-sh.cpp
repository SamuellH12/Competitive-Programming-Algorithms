#include <bits/stdc++.h>
#include "fexp.cpp" //LATEX_IGNORED_LINE
#define ll long long
using namespace std;

const ll mod = 998244353, root = 3; //// 9e8 < mod < 1e9
const ll iroot = fexp(root, mod-2);

void ntt(vector<ll> &a, bool inverse=false){
	int n = a.size(), L = 31 - __builtin_clz(n);
	vector<int> rev(n);
	for(int i=0; i<n; i++) rev[i] = (rev[i/2] | (i&1)<<L)/2;
	for(int i=0; i<n; i++) if(i<rev[i]) swap(a[i], a[rev[i]]);

	for(int k=1; k<n; k<<=1){
		ll wlen = fexp(inverse ? iroot : root, (mod-1) / (k+k));
		for(int i=0; i<n; i+=k+k){  ll w(1);
			for(int j=0; j<k; j++, w = w * wlen % mod){
				ll u = a[i+j];
				ll v = a[i+j+k] * w % mod;
				a[i+j] = u+v - (u+v >= mod ? mod : 0);
				a[i+j+k] = u-v + (u<v ? mod : 0);
			}
		}
	}
	if(inverse){
		ll inv = fexp(n, mod - 2);
		for(auto &x : a) x = x*inv % mod;
	}
}

vector<ll> conv(vector<ll> a, vector<ll> b){
	if(a.empty() || b.empty()) return {};
	int m = a.size()+b.size()-1, n=1<<(32-__builtin_clz(m));
	a.resize(n); b.resize(n);
	
	ntt(a); ntt(b);
	for(int i=0; i<n; i++) a[i] = a[i] * b[i] % mod;
	ntt(a, true);

	return {a.begin(), a.begin() + m};
}
