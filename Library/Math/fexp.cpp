#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll MOD = 1e9 + 7;


ll fexp(ll b, ll p){
	ll ans = 1;

	while(p){
		if(p&1) ans = (ans*b) % MOD;
		b = b * b % MOD;
		p >>= 1;
	}

	return ans % MOD;
}



int main(){
	cout << "Fast Exponentiation" << endl;
	return 0;	
}


/****************************************
Complexidade: O(Log P)

b - Base
p - Potência
MOD - Módulo
*****************************************/