#include <bits/stdc++.h>
using namespace std;
const int ALPHA = 26, off = 'a';
struct Node {
    Node* p  = NULL;
    Node* sl = NULL;
    Node* ol = NULL;
    array<Node*, ALPHA> nxt;
    
    char c;
    int idw = -1;

    Node(){ nxt.fill(NULL); }
    Node(Node* p, char c) : p(p), c(c) { nxt.fill(NULL); }
};
typedef Node* trie;
struct Aho {
    trie root;
    int nwords = 0;
    Aho(){ root = new Node(); }

    void add(string &s){
        trie t = root;
        for(auto c : s){ c -= off;
            if(!t->nxt[c])
                t->nxt[c] = new Node(t, c);
            t = t->nxt[c];
        }
        t->idw = nwords++; //cuidado com strings iguais! use vector
    }

    void buildSufixLink(){
        deque<trie> q(1, root);

        while(!q.empty()){
            trie t = q.front();
            q.pop_front();

            if(trie w = t->p){
                do w = w->sl; while(w && !w->nxt[t->c]);
                t->sl = w ? w->nxt[t->c] : root;
                t->ol = t->sl->idw == -1 ? t->sl->ol : t->sl;
            }

            for(int c=0; c<ALPHA; c++)
                if(t->nxt[c])
                    q.push_back(t->nxt[c]);
        }
    }

    vector<bool> findPattern(string &s){
        vector<bool> ans(nwords, 0);
        trie w = root;
        for(auto c : s){ c -= off;
            while(w && !w->nxt[c]) w = w->sl;  // trie next(w, c)
            w = w ? w->nxt[c] : root;

            for(trie z=w, nl; z; nl=z->ol, z->ol=NULL, z=nl)
                if(z->idw != -1) //get ALL occ: dont delete ol (may slow)
                    ans[z->idw] = true;
        }
        return ans;
    }
};


/*LATEX_DESC_BEGIN***************************
Aho-Corasick: Trie automaton to search multiple patterns in a text
**Complexity:** O(SUM|P| + |S|) * ALPHA

for(auto p: patterns) aho.add(p);
aho.buildSufixLink();
auto ans = aho.findPattern(s);

parent(p), sufixLink(sl), outputLink(ol), patternID(idw)
outputLink -> edge to other pattern end (when p is a sufix of it)
ALPHA -> Size of the alphabet. If big, consider changing nxt to map

To find ALL occurrences of all patterns, don't delete ol in findPattern. But it can be slow (at number of occ), so consider using DP on the automaton.
If you need a **nextState** function, create it using the while in findPattern.
if you need to **store node indexes** add int i to Node, and in Aho add this and change the new Node() to it:
vector<trie> nodes;
trie new_Node(trie p, char c){
    nodes.push_back(new Node(p, c));
    nodes.back()->i = nodes.size()-1;
    return nodes.back();
}
*****************************LATEX_DESC_END*/