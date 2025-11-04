#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double //(10% slower if long double)
typedef complex<ld> CD;

void fft(vector<CD>& a){
	int n = a.size(), L = 31 - __builtin_clz(n);

	static vector<complex<long double>> R(2, 1);
	static vector<CD> rt(2, 1);
	
    for(static int k = 2; k < n; k *= 2){
        auto x = polar(1.0L, acos(-1.0L)/k);
        R.resize(n); rt.resize(n);

		for(int i=k; i<2*k; i++) 
            rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}

	vector<int> rev(n);
	for(int i=0; i<n; i++) rev[i] = (rev[i/2] | (i&1)<<L)/2;
	for(int i=0; i<n; i++) if(i<rev[i]) swap(a[i], a[rev[i]]);
	
    for(int k=1; k<n; k*=2)
		for(int i=0; i<n; i+=2*k)
            for(int j=0; j<k; j++){
                auto x=(ld*)&rt[j+k], y=(ld*)&a[i+j+k];
                CD z (x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);
            //  CD z = rt[j+k] * a[i+j+k]; //(~25% slower,but less code. Delete 2lines above)
                a[i+j+k] = a[i+j] - z;
                a[i+j] += z;
		    }
}

vector<ld> conv(const vector<ld>& a, const vector<ld>& b){
	if(a.empty() || b.empty()) return {};
    vector<ld> res(a.size() + b.size() - 1);
    int n = 1<<(32 - __builtin_clz(res.size()));

    vector<CD> in(n), out(n);
    copy(begin(a), end(a), begin(in));
    for(int i=0; i<b.size(); i++) in[i].imag(b[i]);

    fft(in); 
    for(auto& x : in) x *= x;
    for(int i=0; i<n; i++) out[i] = in[-i&(n-1)] - conj(in[i]);
    fft(out);	
    
    for(int i=0; i<res.size(); i++) res[i] = imag(out[i]) / (4*n);
    return res;
}

/*LATEX_DESC_BEGIN***************************
**Fast Fourier Transform** for polynomials multiplication

@\texttt{conv(a, b) = c}, where $c[x] = \sum a[i]b[x-i]$.@

@fft(a) computes $\hat f(k) = \sum_x a[x] \exp(2\pi i \cdot k x / N)$@ for all k. N must be a power of 2.

@Rounding is safe if $(\sum a_i^2 + \sum b_i^2)\log_2{N} < 9\cdot10^{14}$@
@(in practice $10^{16}$; higher for random inputs).@
 
O(N log N) // N=|A|+|B| (1s N <= 2^22)

||      +++ Four Sum i<j<k<l +++        ||     +++ Tree Sum i<j<k +++       ||
|| iiii = vx4;                          || iii = vx3; // vx3[i*3] = v[i]    ||
|| iiij = conv(vx3, v);                 || iij = conv(vx2, v);              ||
|| iijj = conv(vx2, vx2);               || ijk = conv(conv(v, v), v);       ||
|| iijk = conv(vx2, conv(v, v));        || ans = (ijk - 3*iij + 2*iii) / 6; ||
|| ijkl = conv(conv(v, v), conv(v, v)); || 
|| ans = (ijkl -6*iijk +3*iijj +8*iiij -6*iiii) / 24;
* similar pra FWHT, mas vx3 vira V^V^V ou V|V|V e etc...
*****************************LATEX_DESC_END*/
//Credits: https://github.com/kth-competitive-programming/kactl/blob/main/content/numerical/FastFourierTransform.h