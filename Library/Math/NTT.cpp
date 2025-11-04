#include <bits/stdc++.h>
#include "fexp.cpp" //LATEX_IGNORED_LINE
#define ll long long
using namespace std;

const ll mod = 998244353, root = 62; //// 9e8 < mod1 < 1e9

void ntt(vector<ll> &a){
	int n = a.size(), L = 31 - __builtin_clz(n);
	
    static vector<ll> rt(2, 1);
	for(static int k=2, s=2; k<n; k*=2, s++){
		rt.resize(n);
		ll z[] = {1, fexp(root, mod >> s)};
		for(int i=k; i<2*k; i++) rt[i] = rt[i/2] * z[i&1] % mod;
	}

	vector<int> rev(n);
	for(int i=0; i<n; i++) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	for(int i=0; i<n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	
    for(int k=1; k<n; k*=2)
		for(int i=0; i<n; i+=2*k) 
            for(int j=0; j<k; j++){
                ll z = rt[j+k] * a[i+j+k] % mod, &ai =a[i+j];
                a[i+j+k] = ai - z + (z>ai? mod:0);
                ai += z - (ai+z>=mod? mod:0);
            }
}

vector<ll> conv(const vector<ll> &a, const vector<ll> &b) {
	if (a.empty() || b.empty()) return {};
	int s = a.size()+b.size()-1, B = 32 - __builtin_clz(s), n = 1<<B;
	
    vector<ll> L(a), R(b), out(n);
	L.resize(n), R.resize(n);
    ntt(L), ntt(R);
	
    int inv = fexp(n, mod - 2);
    for(int i=0; i<n; i++) out[-i&(n-1)] = L[i]*R[i] % mod * inv % mod;
	
    ntt(out);
    return {out.begin(), out.begin() + s};
}

const ll mod2 = 918552577, root2 = 63; // 9e8 < mod2 < 1e9 //also valid mods
const ll mod3 = 7340033,   root3 = 25; // 7e6 < mod3 < 1e7 

/*BLOCK_DESC_BEGIN  Computes the first LIM terms of P(x)^K in O(n*limit) BLOCK_DESC_END*/
vector<ll> power(vector<ll> &p, int k, int limit=-1){ //O(n*limit)
    while(p.back() == 0) p.pop_back();
    if(p.empty() || limit == 0) return {};
    if(limit == -1) limit = (p.size()-1) * k;

    vector<ll> ans(limit+1, 0);
    ans[0] = fexp(p[0], k);

    for(int i=1; i<=limit; i++){
        for(int j=1; j <= i && j < p.size(); j++){
            ans[i] += p[j] * ans[i-j] % mod * (k*j - (i-j)) % mod;
            ans[i] %= mod;
        }
        ans[i] = ans[i] * fexp(i * p[0] % mod, mod-2) % mod;
    }
    return ans;
}

/*LATEX_DESC_BEGIN***************************
**Number Theoretic Transform for polynomials multiplication MOD**

@\texttt{conv(a, b) = c}, where $c[x] = \sum a[i]b[x-i]$.@ 

!!! Inputs must be in [0, mod). !!!

For manual convolution: NTT the inputs, multiply pointwise, divide by n, reverse(start+1, end), NTT back.
Consider using template<const ll mod, const ll root> in conv and ntt if you need more than one mod. 
Mod primes must be of the form @$2^a b+1$@,
Consider using CRT (Chinese Remainder Theorem) or FFTmod if you need a different MOD.
@ntt(a) computes $\hat f(k) = \sum_x a[x] g^{xk}$ for all $k$, where $g=\text{root}^{(mod-1)/N}$.@

O(N log N)
*****************************LATEX_DESC_END*/

//Credits: https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/NumberTheoreticTransform.h