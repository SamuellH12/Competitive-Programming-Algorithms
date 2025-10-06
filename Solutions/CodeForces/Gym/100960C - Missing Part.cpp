#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353, root = 62; //// 9e8 < mod1 < 1e9

ll fexp(ll b, ll p){
	ll ans = 1;
	while(p){
		if(p&1) ans = ans * b % mod;
		b = b * b % mod;
		p >>= 1;
	}
	return ans;
}

void ntt(vector<ll> &a){
	int n = a.size(), L = 31 - __builtin_clz(n);
	
    static vector<ll> rt(2, 1);
	for(static int k=2, s=2; k<n; k*=2, s++){
		rt.resize(n);
		ll z[] = {1, fexp(root, mod >> s)};
		for(int i=k; i<2*k; i++) rt[i] = rt[i/2] * z[i&1] % mod;
	}

	vector<int> rev(n);
	for(int i=0; i<n; i++) rev[i] = (rev[i/2] | (i&1) << L) / 2;
	for(int i=0; i<n; i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
	
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

vector<ll> con [10][10];

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); 

	string s, t;
	cin >> s >> t;
	int n = s.size();

	s += s;
	reverse(begin(t), end(t));

	int ans = n;
	vector<ll> a(n+n), b(n);
	
	for(char c='A'; c<='E'; c++){
		for(int i=0; i<n+n; i++) a[i] = (s[i] == c);

		for(char d='a'; d<='e'; d++){
			for(int i=0; i<n; i++) b[i] = (t[i] == d);
			
			auto cv = conv(a, b);
			con[c-'A'][d-'a'] = {begin(cv)+n-1, begin(cv)+n+n-1};
		}
	}
	
	string pat = "abcde";
	do {
		vector<int> mis(n, n);

		for(char c=0; c<='e'-'a'; c++){
			auto &cv = con[c][pat[c]-'a'];
			for(int i=0; i<n; i++) mis[i] -= cv[i];
		}

		for(auto &x : mis) ans = min(ans, x);
	} while(next_permutation(begin(pat), end(pat)));

	cout << ans << endl;
}
