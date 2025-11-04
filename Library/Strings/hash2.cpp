#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e6 + 5;

const ll MOD1 = 131'807'699;
const ll MOD2 = 1e9 + 9;
const ll base = 157;
 
ll expb1[MAXN], expb2[MAXN];
 
#warning "Call precalc() before use StringHash"
void precalc(){ 
    expb1[0] = expb2[0] = 1;
    
	for(int i=1;i<MAXN;i++)
        expb1[i] = expb1[i-1]*base % MOD1,
        expb2[i] = expb2[i-1]*base % MOD2;
}

struct StringHash{
    vector<pair<ll,ll>> hsh;
    string s; // comment S if you dont need it

    StringHash(string& s) : s(s){ 
        hsh.assign(s.size()+1, {0,0});

        for (int i=0;i<s.size();i++)
            hsh[i+1].first  = ( hsh[i].first *base % MOD1 + s[i] ) % MOD1,
            hsh[i+1].second = ( hsh[i].second*base % MOD2 + s[i] ) % MOD2;
    }
 
    ll gethash(int a,int b){
        ll h1 = (MOD1+ hsh[b+1].first  - hsh[a].first *expb1[b-a+1] % MOD1) % MOD1;
        ll h2 = (MOD2+ hsh[b+1].second - hsh[a].second*expb2[b-a+1] % MOD2) % MOD2;
        return (h1<<32) | h2;
    }
};

// OPTIONAL
int firstDiff(StringHash& a, int la, int ra, StringHash& b, int lb, int rb){
	int l=0, r=min(ra-la, rb-lb), diff=r+1;	
	while(l <= r){	
		int m = (l+r)/2;
		if(a.gethash(la, la+m) == b.gethash(lb, lb+m)) l = m+1;
		else r = m-1, diff = m;
	}
	return diff;
}

int hshComp(StringHash& a, int la, int ra, StringHash& b, int lb, int rb){
	int diff = firstDiff(a, la, ra, b, lb, rb);
	if(diff > ra-la && ra-la == rb-lb) return 0; //equal
	if(diff > ra-la || diff  >  rb-lb) return ra-la < rb-lb ? -2 : +2; //prefix of the other
	return a.s[la+diff] < b.s[lb+diff] ? -1 : +1;
}

/*LATEX_DESC_BEGIN***************************
**String Hash** - Double Hash
precalc()    -> O(N)
StringHash() -> O(|S|)
gethash()    -> O(1)

StringHash hash(s);	-> Cria o Hash da string s
hash.gethash(l, r); -> Hash [L,R] (0-Indexado)
*****************************LATEX_DESC_END*/