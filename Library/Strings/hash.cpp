#include <bits/stdc++.h>
#define ll long long
using namespace std;


const int MAXN = 1e6 + 5;

const ll MOD = 1e9 + 7; //WA? Muda o MOD e a base
const ll base = 153;

ll expBase[MAXN];


void precalc(){
	expBase[0] = 1;
	for(int i=1; i<MAXN; i++) 
		expBase[i] = (expBase[i-1]*base)%MOD;
}


struct StringHash{
	vector<ll> hsh;
	int size;

	StringHash(string &_s){
		hsh = vector<ll>(_s.size()+1, 0);
		size = _s.length();
		for(int i=0; i<_s.size(); i++)
			hsh[i+1] = ((hsh[i]*base) % MOD +_s[i]) % MOD;
	}
	
	ll gethash(int l, int r){
		return (MOD + hsh[r+1] - (hsh[l]*expBase[r-l+1]) % MOD ) % MOD;
	}
};



int main(){	
	cout << "String Hash" << endl;
	return 0;	
}

/******************************************************
String Hash

Complexidade:
precalc()    -> O(N)
StringHash() -> O(|S|)
gethash()    -> O(1)

StringHash hash(s);	-> Cria uma struct de StringHash para a string s
hash.gethash(l, r); -> Retorna o hash do intervalo L R da string (0-Indexado)

IMPORTANTE! Chamar precalc() no início do código

const ll MOD  = 131'807'699; -> Big Prime Number 
const ll base = 127;         -> Random number larger than the Alphabet

*******************************************************/


/************************
Some Big Prime Numbers:
127
157
1'201
1'000'003
1'000'037
37'139'213
127'065'427
131'807'699
*************************/