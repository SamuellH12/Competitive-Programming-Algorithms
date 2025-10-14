#include <bits/stdc++.h>
#include "fexp.cpp" //LATEX_IGNORED_LINE
#define ll long long
using namespace std;
const ll mod = 1e9+7;//LATEX_IGNORED_LINE

struct mint {
	ll v = 0;
	mint(ll x=0) : v((x%mod+mod)%mod){}
	mint operator+ (const mint &b) const { ll a = v+b.v; return a < mod ? a : a-mod; }
	mint operator- (const mint &b) const { ll a = v-b.v; return a <  0  ? a+mod : a; }
	mint operator* (const mint &b) const { return v * b.v % mod; }
	mint operator/ (const mint &b) const { return v * fexp(b.v, mod-2) % mod;  }
};
// Extra Operators - Bool Operators
bool operator==(const mint&a, const mint &b){ return a.v == b.v; }
bool operator!=(const mint&a, const mint &b){ return a.v != b.v; }
bool operator< (const mint&a, const mint &b){ return a.v <  b.v; }
// Assignment Operators
mint operator+= (mint&a, const mint &b){ return a = a + b; } 
mint operator-= (mint&a, const mint &b){ return a = a - b; }
mint operator*= (mint&a, const mint &b){ return a = a * b; }
mint operator/= (mint&a, const mint &b){ return a = a / b; }