#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1620

const int SIGMA = 26 + 32;
const int OFF = 'A';

struct node {
    node* p = NULL;
    node* sl = NULL;
    array<node*, SIGMA> son;
    char c;
    vector<int> end;
    node* ol = NULL;

    node(){ son.fill(NULL); }
    node(node* p, char c) : p(p), c(c) { son.fill(NULL); }
};

typedef node* trie;

void add(string &s, trie t, int id){
    for(auto c : s){
        c -= OFF;
        if(!t->son[c])
            t->son[c] = new node(t, c);
        t = t->son[c];
    }
    t->end.push_back(id); //the strings are unique? 
}

void buildSufixLink(trie root){
    deque<trie> q;
    q.push_back(root);

    while(!q.empty()){
        trie t = q.front();
        q.pop_front();

        if(trie w = t->p){
            w = w->sl;
            while(w && !w->son[t->c]) w = w->sl;
            t->sl = w ? w->son[t->c] : root;
            t->ol = t->sl->end.empty() ? t->sl->ol : t->sl;
        } 


        for(int c=0; c<SIGMA; c++)
            if(t->son[c])
                q.push_back(t->son[c]);
    }

    root->sl = NULL;
}

vector<bool> findPattern(string &s, trie root, int q){
    vector<bool> ans(q, 0);
    trie w = root;
    for(int i=0, c; i<s.size(); i++){
        c = s[i] - OFF;
        while(w && !w->son[c]) w = w->sl;
        w = w ? w->son[c] : root;

        for(trie ol=w, nol; ol; nol=ol->ol, ol->ol=NULL, ol=nol) //find at least one occurence of each pattern
            if(!ol->end.empty()){  
                for(auto idx : ol->end)
                    ans[idx] = true;
            }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int tt;
    cin >> tt;
    while(tt--)
    {
        string s, t;
        cin >> s;

        trie tri = new node();
        
        int q; cin >> q;
        for(int i=0; i<q; i++){
            cin >> t;
            add(t, tri ,i);
        }

        buildSufixLink(tri);

        auto ans = findPattern(s, tri, q);

        for(auto x : ans) cout << "ny"[x] << endl;
    }
}

/*
1
abcdefabcde
4
abcde
bcde
cde
bcd

*/