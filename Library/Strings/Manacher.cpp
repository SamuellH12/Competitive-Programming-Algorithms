#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(string &st){
	string s = "$_";
	for(char c : st){ s += c; s += "_"; }
	s += "#";

	int n = s.size()-2, l=1, r=1;
	vector<int> p(n+2, 0);

	for(int i=1, j; i<=n; i++){	
		p[i] = max(0, min(r-i, p[l+r-i]) );	//atualizo o valor atual para o valor do palindromo espelho na string ou para o total que está contido
		while( s[i-p[i]] == s[i+p[i]] ) p[i]++;
		if( i+p[i] > r ) l = i-p[i], r = i+p[i];
	}

	for(auto &x : p) x--; //o valor de p[i] era o tamanho do palindromo + 1
	return p; //agora é o tamanho real
}

/*LATEX_DESC_BEGIN***************************
**Manacher Algorithm** - O(N)
Find every palindrome in string
*****************************LATEX_DESC_END*/