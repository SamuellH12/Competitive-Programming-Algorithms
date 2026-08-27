#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct XorBasis {
    array<ll, 64> base;
    XorBasis(){ base.fill(0); }
    int sz = 0;
    
    void add(ll x){
        while(x){
            int i = 63 - __builtin_clzll(x);
            if(!base[i]) base[i] = x, sz++;
            x ^= base[i];
        }
    }

    ll get_kth(ll k){
        if(b.size() < sz) escalona();
        if(k >= (1LL<<sz)) return -1;
        
        ll ans = 0;
        for(int i=0; i<sz; i++)
        if(k&(1LL<<i))
        ans ^= b[i];
        
        return ans;
    }

private:
    vector<ll> b;
    void escalona(){
        b.clear();
        for(int i=0; i<64; i++) if(base[i])
            for(int j=i+1; j<64; j++) if(base[j]&(1LL<<i))
                base[j] ^= base[i];
        for(auto &x : base) if(x) b.push_back(x);
    }
};


// LATEX_IGNORED_BEGIN 
int main(){
    int q; cin >> q;
    XorBasis g;
    while(q--){
        ll op, x; cin >> op >> x;
        if(op&1) g.add(x);
        else cout << g.get_kth(x-1) << "\n";
    }
}
// LATEX_IGNORED_END