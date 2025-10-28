#include <bits/stdc++.h>
using namespace std;

const int ALPHA = 26, off = 'a';
struct Node {
    array<Node*, ALPHA> nxt;
    int terminal = 0; 
    Node() { nxt.fill(NULL); }
};

struct Trie {
	Node* root;
	Trie(){ root = new Node(); }
	
	void add(string &s){
		Node* t = root;
		for(auto c : s){ c -= off;
			if(!t->nxt[c])
				t->nxt[c] = new Node();
			t = t->nxt[c];
		}
		t->terminal++;
	}

	int count(string &s){
		Node* t = root;
		for(auto c : s){ c -= off;
			if(!t->nxt[c]) return 0;
			t = t->nxt[c];
		}
		return t->terminal;
	}
};

/*LATEX_DESC_BEGIN***************************
Trie - Arvore de Prefixos
insert(P) - O(|P|)
count(P)  - O(|P|)
sigma - Tamanho do alfabeto
off   - primeiro simbolo do alfabeto (offset)
*****************************LATEX_DESC_END*/