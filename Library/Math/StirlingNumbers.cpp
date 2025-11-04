#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e3; //LATEX_IGNORED_LINE
#include "Combinatorics.cpp"

ll st1[MAXN][MAXN];
void StirlingFirst_nn(){ // O(n^2)
    st1[0][0] = 1;

    for(int n=1; n<MAXN; n++)
        for(int k=1; k<=n; k++)
            st1[n][k] = (n-1) * st1[n-1][k] + st1[n-1][k-1];
}

ll st2[MAXN][MAXN];
void StirlingSecond_nn(){ // O(n^2)
    st2[0][0] = 1;

    for(int n=1; n<MAXN; n++)
        for(int k=1; k<=n; k++)
            st2[n][k] = k * st2[n-1][k] + st2[n-1][k-1];
}

//// Fixed N ////
#include "NTT.cpp"

vector<ll> shift(vector<ll> pol, ll n){ //para StirlingFirst
        ll s = pol.size(), k = 1;
        vector<ll> a(s), b(s);
        for(int i=0; i<s; i++, k=k*n%mod){
            a[i] = pol[i] * fat[i] % mod;
            b[s-i-1] = k * finv[i] % mod;
        }
        a = conv(a, b);
        for(int i=0; i<s; i++) pol[i] = a[s-1+i] * finv[i] % mod;
        return pol;
}

vector<ll> StirlingFirst(ll n, bool sign = false){  //O(n log^2 n) //lembrar do fat/finv
    if(n == 0) return {1};
    vector<ll> pol(n+1), q = n&1 ? StirlingFirst(n-1) : StirlingFirst(n/2);

	if(n&1){
        for(int i=0; i<n-1; i++) 
            pol[i+1] = (q[i] + q[i+1] * (n-1)) % mod;
        pol[n] = 1;
    }
	else pol = conv(q, shift(q, n/2));

    if(sign&&n&1) for(int i=0; i<n/2+1; i++) pol[i*2]   = (mod - pol[i*2])   % mod;
    if(sign>(n&1))for(int i=0; i<n/2;   i++) pol[i*2+1] = (mod - pol[i*2+1]) % mod;

    return pol;
}

vector<ll> StirlingSecond(int n){ //O(n log^2 n) //lembrar do fat/finv
    vector<ll> a(n+1), b(n+1);
    for(int i=0; i<n+1; i++){
        a[i] = fexp(i, n) * finv[i] % mod;
        b[i] = i&1 ? mod - finv[i] : finv[i];
    }
    a = conv(a, b);
    return {begin(a), begin(a)+n+1};
}
