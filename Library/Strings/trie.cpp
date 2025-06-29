#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e5 + 10;
const int sigma = 26;

int trie[MAXS][sigma], terminal[MAXS], z = 1;

void insert(string &p){
	int cur = 0;

	for(int i=0; i<p.size(); i++){
		int id = p[i] - 'a';

		if(trie[cur][id] == -1 ){
			memset(trie[z], -1, sizeof trie[z]);
			trie[cur][id] = z++;
		}

		cur = trie[cur][id];
	}

	terminal[cur]++;
}

int count(string &p){
	int cur = 0;

	for(int i=0; i<p.size(); i++){
		int id = (p[i] - 'a');

		if(trie[cur][id] == -1) return 0;

		cur = trie[cur][id];
	}
	return terminal[cur];
}

void init(){
	memset(trie[0], -1, sizeof trie[0]);
	z = 1;
}
/*LATEX_DESC_BEGIN***************************
Trie - Arvore de Prefixos
insert(P) - O(|P|)
count(P)  - O(|P|)
MAXS  - Soma do tamanho de todas as Strings
sigma - Tamanho do alfabeto
*****************************LATEX_DESC_END*/