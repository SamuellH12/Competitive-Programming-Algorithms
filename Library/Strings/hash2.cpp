#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 5;

const ll MOD1 = 131'807'699;
const ll MOD2 = 1e9 + 9;
const ll base = 157;
 
ll expBase1[MAXN];
ll expBase2[MAXN];
 
void precalc(){
    expBase1[0] = expBase2[0] = 1;
    
	for(int i=1;i<MAXN;i++)
        expBase1[i] = ( expBase1[i-1]*base ) % MOD1,
        expBase2[i] = ( expBase2[i-1]*base ) % MOD2;
}
 
struct StringHash{
    vector<pair<ll,ll>> hsh;
    
    StringHash(string& _s){     //!!! RUN PRECALC FIRST !!!
        hsh = vector<pair<ll,ll>> (_s.size()+1, {0,0});

        for (int i=0;i<_s.size();i++)
            hsh[i+1].first  = ( (hsh[i].first *base) % MOD1 + _s[i] ) % MOD1,
            hsh[i+1].second = ( (hsh[i].second*base) % MOD2 + _s[i] ) % MOD2;
    }
 
    ll gethash(int a,int b)
	{
        ll h1 = (MOD1 + hsh[b+1].first  - ( hsh[a].first *expBase1[b-a+1] ) % MOD1) % MOD1;
        ll h2 = (MOD2 + hsh[b+1].second - ( hsh[a].second*expBase2[b-a+1] ) % MOD2) % MOD2;
        return (h1<<32LL) | h2;
    }
};

/******************************************************
String Hash - Double Hash

Complexidade:
precalc()    -> O(N)
StringHash() -> O(|S|)
gethash()    -> O(1)

StringHash hash(s);	-> Cria uma struct de StringHash para a string s
hash.gethash(l, r); -> Retorna um pair com os dois hashs do intervalo L R da string (0-Indexado)

IMPORTANTE! Chamar precalc() no início do código

const ll MOD1 = 131'807'699; -> Big Prime Number for hash 1
const ll MOD1 = 127'065'427; -> Big Prime Number for hash 2
const ll base = 127;         -> Random number larger than the Alphabet
*******************************************************/
/************************
Some Big Prime Numbers:
37'139'213
127'065'427
131'807'699
*************************/