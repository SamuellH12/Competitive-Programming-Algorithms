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
    int n = a.size(); // 1<<(32 - __builtin_clz(res.size()));
    vector<ld> res(a.size());

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

const int MAXN = 1<<17; // 2*20000 + 10;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); 

	int n; cin >> n;

	vector<ld> v1(MAXN), vx2(MAXN);

	for(int i=0, x; i<n; i++){
		cin >> x;
		v1[(x+MAXN) %MAXN] += 1;
		vx2[(x+MAXN)*2 %MAXN] += 1;
	}

	auto viii = vector<ld>(MAXN); for(int i=0; i<MAXN; i++) viii[(i*3)%MAXN] = v1[i]; // iii
	auto viij = conv(vx2, v1); // iij (iii)
	auto vijk = conv(conv(v1, v1), v1); // ijk (iii, iij, ...)
	
	for(int i=-MAXN/2; i<MAXN/2; i++){
		int j = (i+MAXN)%MAXN;
		ll ijk = vijk[j]+0.5;
		ll iij = viij[j]+0.5;
		ll iii = viii[j]+0.5;
		
		ll ans = (ijk - 3*iij + 2*iii) / 6;

		if(ans) cout << i << " : " << ans << "\n";
	}
}
