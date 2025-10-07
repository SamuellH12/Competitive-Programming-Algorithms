#include <bits/stdc++.h>
#define ll long long
using namespace std;
#include "FFT.cpp"

template<const int mod> vector<ll> convMod(const vector<ll> &a, const vector<ll> &b){
	if (a.empty() || b.empty()) return {};
	vector<ll> res(a.size() + b.size() - 1);
	int B=32-__builtin_clz(res.size()), n=1<<B, cut=int(sqrt(mod));
	vector<CD> L(n), R(n), outs(n), outl(n);
	
    for(int i=0; i<a.size(); i++) L[i] = CD((int)a[i] / cut, (int)a[i] % cut);
	for(int i=0; i<b.size(); i++) R[i] = CD((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);

	for(int i=0; i<n; i++){
		int j = -i&(n-1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
    fft(outl), fft(outs);
	
    for(int i=0; i<res.size(); i++){
		ll av = (ll)(real(outl[i])+.5) % mod;
		ll bv = (ll)(imag(outl[i])+.5) + (ll)(real(outs[i])+.5);
        ll cv = (ll)(imag(outs[i])+.5);
		res[i] = ((av * cut + bv) % mod * cut + cv) % mod;
	}
	return res;
}

/*LATEX_DESC_BEGIN***************************
Fast Fourier Transform for polynomials multiplication with MOD
FFT com **ALTA PRECISÃO** (não precisa do mod, só coloque cut=1<<15)
Can be used for convolutions modulo arbitrary integers.
@as long as $N\log_2N\cdot \text{mod} < 8.6 \cdot 10^{14}$ (in practice $10^{16}$ or higher).@

!!! Inputs must be in [0, mod). !!!
@\textit{Get the fft function from fft section.}@
O(N log N) // (2x slower than NTT or FFT)
*****************************LATEX_DESC_END*/
//Credits: https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastFourierTransformMod.h