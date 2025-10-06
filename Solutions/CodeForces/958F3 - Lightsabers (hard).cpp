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

const int MOD = 1009;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); 

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> cnt(m);
	
	for(int i=0, x; i<n; i++){
		cin >> x;
		cnt[--x]++;
	}
	
	vector<ld> ans = {1};
	priority_queue<pair<int, vector<ld>>> pq;
	pq.emplace(-1, ans);
	
	for(int i=0; i<m; i++){
		vector<ld> b(cnt[i]+1, 1);
		pq.emplace(-b.size(), b);
	}

	while(pq.size() > 1){
		auto [_, a] = pq.top(); pq.pop();
		auto [__, b] = pq.top(); pq.pop();
		a = conv(a, b);
		a[0] = 1;
		if(a.size() > k+1) a.resize(k+1);
		for(auto &x : a) x = (ll)round(x) % MOD;
		pq.emplace(-a.size(), a);
	}

	ans = pq.top().second;
	cout << (ll)round(ans[k]) % MOD << endl;

	return 0;	
}
