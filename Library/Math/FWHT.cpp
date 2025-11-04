#include <bits/stdc++.h>
#define ll long long
using namespace std;

template<const char op> 
vector<ll> FWHT(vector<ll> a, const bool inv = false){
    int n = a.size();
    for(int len=1; len<n; len+=len)
        for(int i=0; i<n; i += 2*len)
            for(int j=0; j<len; j++){
                ll u = a[i+j], v = a[i+j+len];   
                if(op == '^') a[i+j]  = u+v, a[i+j+len] = u-v;
                if(op == '|') a[i+j+len] = v + (inv ? -u : +u);
                if(op == '&') a[i+j]     = u + (inv ? -v : +v);
            }
    
    if(op=='^'&&inv) for(auto &x : a) x /= n;
    return a;
}
 
template<const char op> 
vector<ll> multiply(vector<ll> a, vector<ll> b){
  int n=1; while(n < max(a.size(), b.size())) n*=2;
  a.resize(n, 0);  b.resize(n, 0);
  a = FWHT<op>(a); b = FWHT<op>(b);
  
  vector<ll> ans(n);
  for(int i=0; i<n; i++) ans[i] = a[i]*b[i] % mod;
  ans = FWHT<op>(ans, true);
  return ans;
}
 

const int mxlog = 17;
vector<ll> subset_multiply(vector<ll> a, vector<ll> b){ //OPTIONAL
    int n = 1; while(n < max(a.size(), b.size())) n <<= 1;
    a.resize(n, 0);  b.resize(n, 0);
    vector<ll> ans(n, 0LL); vector A(mxlog+1, vector<ll>(n)), B = A;
    for(int i=0; i<n; i++) A[__builtin_popcount(i)][i]=a[i], B[__builtin_popcount(i)][i]=b[i];
    for(int i=0; i<=mxlog; i++) A[i] = FWHT<'|'>(A[i]), B[i] = FWHT<'|'>(B[i]);
    for(int i=0; i<=mxlog; i++){
        vector<ll> C(n);
        for(int x=0; x<=i; x++) 
            for(int j=0; j<n; j++) 
                C[j] += A[x][j] * B[i-x][j];
        
        C = FWHT<'|'>(C, true);
        for(int j=0; j < n; j++)
            if(__builtin_popcount(j) == i)
                ans[j] += C[j];
    }
    return ans;
}

/*LATEX_DESC_BEGIN***************************
Fast Walsh Hadamard Transform - **Convolução de XOR, OR e AND**
O(N log N)
*****************************LATEX_DESC_END*/
// Credits: https://github.com/gabrielpessoa1/ICPC-Library/blob/master/code/Math/FastWalshHadamardTransform.cpp