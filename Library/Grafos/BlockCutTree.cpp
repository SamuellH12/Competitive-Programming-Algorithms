#include <bits/stdc++.h>
using namespace std;

struct BlockCutTree {
    vector<vector<int>> g, tree, comp;
    vector<int> id, cut;
    BlockCutTree(int n) : n(n), g(n), cut(n) {}

    void addEdge(int u, int v){
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    void build(){ 
        pre = low = id = vector<int>(n, -1);
        for(int u=0; u<n; u++, chd=0) if(pre[u] == -1) //if graph is disconected
            tarjan(u, -1), makeComp(-1);               //find cut vertex and make components
        
        for(int u=0; u<n; u++) if(cut[u]) comp.emplace_back(1, u); //create cut components
        for(int i=0; i<comp.size(); i++)                           //mark id of each node
            for(auto u : comp[i]) id[u] = i;
        
        tree.resize(comp.size());
        for(int i=0; i<comp.size(); i++)
            for(auto u : comp[i]) if(id[u] != i) 
                tree[i].push_back(id[u]),
                tree[id[u]].push_back(i);
    }
private:
    vector<int> pre, low;
    vector<pair<int, int>> st;
    int n, clk = 0, chd=0, ct, a, b;
    
    void makeComp(int u){
        comp.emplace_back();
        do {
            tie(a, b) = st.back(); 
            st.pop_back();
            comp.back().push_back(b);
        } while(a != u);
        if(~u) comp.back().push_back(u);
    }

    void tarjan(int u, int p){
        pre[u] = low[u] = clk++;
        st.emplace_back(p, u);

        for(auto v : g[u]) if(v != p){
            if(pre[v] == -1){
                tarjan(v, u);
                low[u]  =  min(low[u], low[v]);
                cut[u] |= ct = (~p && low[v] >= pre[u]) || (p==-1 && ++chd >= 2);
                if(ct) makeComp(u);
            }
            else low[u] = min(low[u], pre[v]);
        }
    }
};


/*LATEX_DESC_BEGIN***************************
Block Cut Tree - BiConnected Component
BlockCutTree bcc(n);
bcc.addEdge(u, v);
bcc.build();

bcc.tree    -> graph of BlockCutTree (tree.size() <= 2n)
bcc.id[u]   -> componet of u in the tree
bcc.cut[u]  -> 1 if u is a cut vertex; 0 otherwise
bcc.comp[i] -> vertex of comp i (cut are part of multiple comp)
*****************************LATEX_DESC_END*/