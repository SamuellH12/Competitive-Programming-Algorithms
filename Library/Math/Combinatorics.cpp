#include <bits/stdc++.h>
#include "fexp.cpp" //LATEX_IGNORED_LINE
#define ll long long
using namespace std;

vector<ll> fat, finv;

void Combin(int n){  // precalc
	fat.assign(n+1, 1);
	for(int i=2; i<=n; i++) fat[i] = fat[i-1]*i % mod;
	finv.assign(n+1, fexp(fat.back(), mod-2));
	for(int i=n; i>0; i--) finv[i-1] = finv[i]*i % mod; 
}

ll choose(ll n, ll k){ if(k>n||k<0) return 0;
	return fat[n] * finv[k] % mod * finv[n-k] % mod; 
} 

ll chooseLinear(ll n, ll k){ //O(k) || min(k, n-k);
	k = max(k, n-k);
	ll ans = 1, inv=1;
	for(int i=n; i>k; i--) ans = ans*i % mod;
	for(int i=1; i<=n-k; i++) inv = inv*i % mod;
	return ans * fexp(inv, mod-2) % mod;
}

ll permRepetition(const vector<int> &cnt){
	ll n = accumulate(begin(cnt), end(cnt), 0ll), ans = fat[n];
	for(int x : cnt) ans = ans * finv[x] % mod;
	return ans;
}

//#Colorir N posicoes com exatamente K cores (equival stirling_2 * k!)
ll RhymingK(ll n, ll k){ //O(K log N)
    ll ans = 0;
    for(int j=0; j<=k; j++)
        if(j&1) ans = (ans + mod - choose(k, k-j) * fexp(k-j, n) % mod) % mod;
        else    ans = (ans +       choose(k, k-j) * fexp(k-j, n) % mod) % mod;
	return ans;
}

ll pascal[5001][5001]; // pascal[n][k] = choose(n, k);
void Pascal(int N){
	pascal[0][0] = 1;
	for(int n=1; n<=N; n++){
		pascal[n][0] = pascal[n][n] = 1;
		for(int k=1; k<n; k++)
			pascal[n][k] = (pascal[n-1][k-1] + pascal[n-1][k]) % mod;
	}
}


////////////////////////////
////// Stars and Bars //////
////////////////////////////

ll starsBars(ll n, ll k){ //O(choose)
	return choose(n+k-1, n); 
}
ll starsLowerBound(ll n, const vector<ll> &lw){ //O(k)
	for(auto x : lw) n -= x;
	return starsBars(n, lw.size());
}
ll starsUpperBound(ll n, ll k, ll up){ //O(k)
	ll ans = 0;
	for(int i=0; i<=k; i++) 
		ans += choose(k, i) * choose(n+k-1-(up+1)*i, k-1) % mod * (i&1? -1:+1);
	return ans;
}
ll starsUpperBound(ll M, const vector<ll> &up){ //O(N*M)
	int N = up.size();
	vector dp(up.size()+1, vector<ll>(N+1));
	for(int m=0; m<=M; m++) dp[0][m] = choose(N+m-1, m);
	for(int n=1; n<=N; n++)
		for(int m=0; m<=M; m++)
			dp[n][m] = dp[n-1][m] - (m-up[n-1]-1 < 0 ? 0 : dp[n-1][m-up[n-1]-1]);
	return dp[N][M];
}
ll starsLowerUpperBound(ll n, const vector<ll> &lw, const vector<ll> &up){ //O(N*M)
	for(auto x : lw) n -= x;
	return starsUpperBound(n, up);
}

///// Propriedades /////
ll sumNci (ll n){ return fexp(2, n); }             //for(i=0; i<=n) sum+=choose(n, i);
ll sumicK (ll n, ll k){ return choose(n+1, k+1); } //for(i=0; i<=n) sum+=choose(i, k);
ll sumNKcK(ll n, ll k){ return choose(n+k+1, k); } //for(i=0; i<=k) sum+=choose(n+i, i);
ll sumNsqr(ll n){ return choose(n+n, n); }         //for(i=0; i<=n) sum+=choose(n, i)**2;
ll catalan(ll n){ return choose(2*n, n) * fexp(n+1, mod-2) % mod; }


// LATEX_IGNORED_BEGIN   pra testar as funções
int main(){
	int N = 10;
	Pascal(N);

	for(int n=0; n<=N; cout << endl, n++)
		for(int k=0; k<=n; k++)
			cout << pascal[n][k] << "\t";
	cout << endl;

	Combin(N);
	
	for(int n=0; n<=N; cout << endl, n++)
		for(int k=0; k<=n; k++)
			cout << choose(n, k) << "\t";
	cout << endl;

	for(int n=0; n<=N; cout << endl, n++)
		for(int k=0; k<=n; k++)
			cout << chooseLinear(n, k) << "\t";
	cout << endl;

	for(int n=0; n<=N; n++) cout << fat[n] << "\t";
	cout << endl;
	for(int n=0; n<=N; n++) cout << n << "\t";
	cout << endl;
	for(int n=0; n<=N; n++) cout << finv[n] << " ";
	cout << endl;
}	
// LATEX_IGNORED_END