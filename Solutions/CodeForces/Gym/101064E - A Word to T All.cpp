#include <bits/stdc++.h>
using namespace std;
#define cerr if(false)cerr
//https://codeforces.com/gym/101064/problem/E
//2016 USP Try-outs
const int ALPHA = 10;
const int off = 'a';

struct Node {
    Node* p  = NULL;
    Node* sl = NULL;
    array<Node*, ALPHA> nxt;
    
    int no = 0;

    char c;
    int mask = 0;

    Node(int id) : no(id){ nxt.fill(NULL); }
    Node(Node* p, char c, int id) : p(p), c(c), no(id) { nxt.fill(NULL); }
};
typedef Node* trie;

struct Aho {
    trie root;
    int nwords = 0, nodesid=0;
    vector<trie> nodes;

    trie new_Node(Node* p, char c){
        trie no = new Node(p, c, nodesid++);
        nodes.push_back(no);
        return no; 
    }

    Aho(){ root = new_Node(NULL, 0); }

    void add(string &s, bool bad=true){
        trie t = root;
        for(auto c : s){ c -= off;
            if(!t->nxt[c])
                t->nxt[c] = new_Node(t, c);
            t = t->nxt[c];
        }
        int id = nwords++;
        t->mask |= 1<<id;
        if(!bad) t->mask = -1;
    }

    void buildSufixLink(){
        deque<trie> q(1, root);

        while(!q.empty()){
            trie t = q.front();
            q.pop_front();

            if(trie w = t->p){
                do w = w->sl; while(w && !w->nxt[t->c]);
                t->sl = w ? w->nxt[t->c] : root;
                t->mask |= t->sl->mask;
            }

            for(int c=0; c<ALPHA; c++)
                if(t->nxt[c])
                    q.push_back(t->nxt[c]);
                else if(t->sl && t->sl->nxt[c])
                    t->nxt[c] = t->sl->nxt[c];
        }
    }
};
Aho aho;

const int MAXN = 310;
int vis[MAXN][1<<15];

int main(){
    memset(vis, -1, sizeof vis);
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    string s;
    for(int i=0; i<n; i++)
        cin >> s, aho.add(s, true);
    
    for(int i=0; i<m; i++)
        cin >> s, aho.add(s, false);

    aho.buildSufixLink();

    deque<pair<int, int>> q;
    q.push_back({0, 0});
    vis[0][0] = -2;
    int ans = -1;

    while(!q.empty())
    {
        auto [u, mask] = q.front();
        q.pop_front();
        
        if(mask == (1<<n)-1){ ans = u; break; }
        
        trie no = aho.nodes[u];
        for(int c=0; c<ALPHA; c++)
            if(no->nxt[c]){
                int v = no->nxt[c]->no, msk = mask|no->nxt[c]->mask;
                if(msk == -1) continue;
                if(vis[v][msk] != -1) continue;
                
                q.push_back({v, msk});
                vis[v][msk] = (u<<15)|mask;
            }
    }
    
    if(ans == -1){
        cout << "-";
        return 0;
    }

    s = "";
    int u = ans, mask = (1<<n)-1;

    while(u || mask){
        s += (char)(off+aho.nodes[u]->c);
        u = vis[u][mask], mask = u;
        u >>= 15; mask ^= u<<15;
    }

    reverse(begin(s), end(s));
    cout << s;
}