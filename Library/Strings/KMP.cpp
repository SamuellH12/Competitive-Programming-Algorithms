#include <bits/stdc++.h>
using namespace std;

vector<int> Pi(string &t){
	vector<int> p(t.size(), 0);

	for(int i=1, j=0; i<t.size(); i++){
		while(j > 0  && t[j] != t[i]) j = p[j-1];
		if(t[j] == t[i]) j++;
		p[i] = j;
	}
	return p;
}

vector<int> kmp(string &s, string &t){
	vector<int> p = Pi(t), occ;

	for(int i=0, j=0; i<s.size(); i++){
		while( j > 0 && s[i] != t[j]) j = p[j-1];
		if(s[i]==t[j]) j++;
		if(j == t.size()) occ.push_back(i-j+1), j = p[j-1];
	}
	return occ;
}

/*BLOCK_DESC_BEGIN **Optional:** KMP Automato. j = state atual [root=j=0] BLOCK_DESC_END*/
struct Automato {
	vector<int> p;
    string t;
	Automato(string &t) : t(t), p(Pi(t)){}
    int next(int j, char c){ //return nxt state
        if(final(j)) j = p[j-1];
        while(j && c != t[j]) j = p[j-1];
        return j + (c == t[j]);
    }
    bool final(int j){ return j == t.size(); }
};

/**************************
KMP - Knuth–Morris–Pratt Pattern Searching
Complexity: O(|S|+|T|)
kmp(s, t) -> returns all occurences of t in s
p = Pi(t) -> p[i] = biggest prefix that is a sufix of t[0,i]
***************************/