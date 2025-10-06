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

vector<ll> fat, finv;
void Combin(int n){  
	fat.assign(n+1, 1);
	for(int i=2; i<=n; i++) fat[i] = fat[i-1]*i % mod;
	finv.assign(n+1, fexp(fat.back(), mod-2));
	for(int i=n; i>0; i--) finv[i-1] = finv[i]*i % mod; 
}
ll choose(ll n, ll k){ assert(n < fat.size()); return k>n||k<0 ? 0 : fat[n] * finv[k] % mod * finv[n-k] % mod; } //precalc O(N)
ll inv(ll x){ return fexp(x, mod-2); }

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); 
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		Combin(n+10);
		
		vector<ll> ans = {1}, at = {1, 1};

		priority_queue<pair<int, vector<ll>>> pq;

		for(int i=0; i<n; i++){
			cin >> at[1];
			pq.emplace(-2, at);
		}

		while(pq.size() > 1){
			ans = pq.top().second; pq.pop();
			at = pq.top().second; pq.pop();
			ans = conv(ans, at);
			pq.emplace(-ans.size(), ans);
		}
		ans = pq.top().second;

		ll sum = 0;
		// for(auto &x : ans) cout << x << " "; cout << endl;
		for(int i=1; i<=n; i++){
			// cout << fat[n] % mod * inv(choose(n, i)) % mod << " ";
			sum += ans[i] * fat[n] % mod * inv(choose(n, i)) % mod;
			sum %= mod;
		}
		
		cout << sum * inv(fat[n]) % mod << endl;
	}
}
