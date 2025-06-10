#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e6 + 5;

const ll MOD = 1e9 + 7; //WA? Muda o MOD e a base
const ll base = 153;

ll expb[MAXN];

void precalc(){
	expb[0] = 1;
	for(int i=1; i<MAXN; i++) 
		expb[i] = (expb[i-1]*base)%MOD;
}

struct StringHash{
	vector<ll> hsh;

	StringHash(string &s){
		hsh.assign(s.size()+1, 0);
		for(int i=0; i<s.size(); i++)
			hsh[i+1] = (hsh[i] * base % MOD + s[i]) % MOD;
	}
	
	ll gethash(int l, int r){
		return (MOD + hsh[r+1] - hsh[l]*expb[r-l+1] % MOD ) % MOD;
	}
};
/******************************************************
String Hash
precalc()    -> O(N)
StringHash() -> O(|S|)
gethash()    -> O(1)

StringHash hash(s);	-> Cria uma struct de StringHash para a string s
hash.gethash(l, r); -> Retorna o hash do intervalo L R da string (0-Indexado)

IMPORTANTE! Chamar precalc() no início do código

const ll MOD  = 131'807'699; -> Big Prime Number 
const ll base = 127;         -> Random number larger than the Alphabet
*******************************************************/