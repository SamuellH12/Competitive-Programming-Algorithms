#include <bits/stdc++.h>
using namespace std;
#define ld double
typedef complex<ld> CD;
const ld PI = acos(-1);

void fft(vector<CD> &a, bool inverse=false){
	int n = a.size(), L = 31 - __builtin_clz(n);
	vector<int> rev(n);
	for(int i=0; i<n; i++) rev[i] = (rev[i/2] | (i&1)<<L)/2;
	for(int i=0; i<n; i++) if(i<rev[i]) swap(a[i], a[rev[i]]);

	for(int k=1; k<n; k<<=1){
		ld ang= PI / k * (inverse ? -1 : +1);
		CD wlen(cos(ang), sin(ang));
		for(int i=0; i<n; i+=k+k){  CD w(1);
			for(int j=0; j<k; j++, w *= wlen){
				CD u = a[i+j];
				CD v = a[i+j+k] * w;
				a[i+j] = u+v;
				a[i+j+k] = u-v;
			}
		}
	}
	if(inverse) for(CD &x : a) x /= n;
}

vector<ld> conv(const vector<ld>& a, const vector<ld>& b){
	if(a.empty() || b.empty()) return {}; //or(32-builtin_clz(m))
	int m = a.size()+b.size()-1, n=1<<__bit_width(m-1);//ifcomp err

	vector<CD> fa(begin(a), end(a)); fa.resize(n);
	vector<CD> fb(begin(b), end(b)); fb.resize(n);
	
	fft(fa); fft(fb);
	for(int i=0; i<n; i++) fa[i] *= fb[i];
	fft(fa, true);

	vector<ld> ans(m);
	for(int i=0; i<m; i++) ans[i] = fa[i].real();
	return ans;
}

/*LATEX_DESC_BEGIN***************************
**Fast Fourier Transform** for polynomials multiplication

@\texttt{conv(a, b) = c}, where $c[x] = \sum a[i]b[x-i]$.@

@fft(a) computes $\hat f(k) = \sum_x a[x] \exp(2\pi i \cdot k x / N)$@ for all k. N must be a power of 2.

@Rounding is safe if $(\sum a_i^2 + \sum b_i^2)\log_2{N} < 9\cdot10^{14}$@
@(in practice $10^{16}$; higher for random inputs).@
 
O(N log N) // N=|A|+|B| (1s N <= 2^22)

|  Four Sum i<j<k<l   ||    Tree Sum i<j<k      |
|iiii = vx4;          || iii = vx3;             |
|iiij = conv(vx3, v)  || iij = conv(vx2, v)     |
|iijj = conv(vx2, vx2)|| ijk = conv(v,v,v)      |
|iijk = conv(vx2, v,v)|| ans=(ijk-3*iij+2*iii)/6|
|ijkl = conv(v,v,v,v) ||  // vx3[i*3] = v[i] //
|ans = (ijkl -6*iijk +3*iijj +8*iiij -6*iiii) / 24
* similar pra FWHT, mas vx3 vira V^V^V ou V|V|V e etc...
*****************************LATEX_DESC_END*/
