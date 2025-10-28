#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e6 + 5;

const array<ll, 2> mod = {131'807'699, 1e9 + 9};
const ll base = 157;
 
array<ll, 2> expb[MAXN];

#warning "Call precalc() before use StringHash"
void precalc(){ 
    expb[0][0] = expb[0][1] = 1;
    
	for(int i=1, j;i<MAXN;i++) for(j=1; ~j; j--)
        expb[i][j] = expb[i-1][j]*base % mod[j];
}

struct StringHash{
    vector<array<ll,2>> hsh;
    string s; // comment S if you dont need it

    StringHash(string& s) : s(s){ 
        hsh.assign(s.size()+1, {0,0});

        for(int i=0, j;i<s.size();i++) for(j=1; ~j; j--)
            hsh[i+1][j] = ( hsh[i][j]*base + s[i] ) % mod[j];
    }
    ll gethash(int a,int b){
        ll h1 = (mod[0]+ hsh[b+1][0] - hsh[a][0]*expb[b-a+1][0] % mod[0]) % mod[0];
        ll h2 = (mod[1]+ hsh[b+1][1] - hsh[a][1]*expb[b-a+1][1] % mod[1]) % mod[1];
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
String Hash - Double Hash
precalc()    -> O(N)
StringHash() -> O(|S|)
gethash()    -> O(1)

StringHash hash(s);	-> Cria o Hash da string s
hash.gethash(l, r); -> Hash [L,R] (0-Indexado)
*****************************LATEX_DESC_END*/