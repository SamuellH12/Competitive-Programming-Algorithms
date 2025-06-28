#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


ll modinverse(ll a, ll b, ll s0 = 1, ll s1 = 0) { return b == 0 ? s0 : modinverse(b, a % b, s1, s0 - s1 * (a / b)); }
ll mul(ll a, ll b, ll m) {
    ll q = (long double) a * (long double) b / (long double) m;
    ll r = a * b - q * m;
    return (r + m) % m;
}

struct Equation {
    ll mod, ans;
    bool valid;
    Equation() { valid = false; }
    Equation(ll a, ll m) { mod = m, ans = (a % m + m) % m, valid = true; }
    Equation(Equation a, Equation b){
        if(!a.valid || !b.valid){ valid = false; return; }
        ll g = gcd(a.mod, b.mod);
        if((a.ans - b.ans) % g != 0){ valid = false; return; }
        
        valid = true;
        mod = a.mod * (b.mod / g);
        ans = a.ans;
        ans += mul( mul(a.mod,  modinverse(a.mod, b.mod), mod),   (b.ans - a.ans) / g, mod);    
        
        ans = (ans % mod + mod) % mod;
    }
    Equation operator+(const Equation& b) const { return Equation(*this, b); }
};

/************* 
Equation eq1(2, 3); // x = 2 mod 3
Equation eq2(3, 5); // x = 3 mod 5
Equation ans = eq1 + eq2;
*************/