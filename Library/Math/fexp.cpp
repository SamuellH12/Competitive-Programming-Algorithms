#define ll long long
ll mod = 1e9 + 7;

ll fexp(ll b, ll p){
	ll ans = 1;
	while(p){
		if(p&1) ans = ans * b % mod;
		b = b * b % mod;
		p >>= 1;
	}
	return ans;
}
// O(Log P) // b - Base // p - Potência