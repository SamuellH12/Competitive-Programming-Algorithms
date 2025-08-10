#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

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
        
        for(int i=0, ct=1; i<comp.size(); i++, ct=1){  //remove components with only cuts
            for(auto u : comp[i]) ct &= cut[u];
            if(ct) swap(comp[i], comp.back()), comp.pop_back(), i--;
        }

        for(int u=0; u<n; u++) if(cut[u]) comp.emplace_back(1, u); //create cut components
        
        for(int i=0; i<comp.size(); i++) //mark id of each node
            for(auto u : comp[i])
                id[u] = i;
        
        tree.resize(comp.size()); //creates tree (looking only edges from cut points)
        pre.assign(comp.size(), 1);

        for(int u=0; u<n; u++) if(cut[u]){
            for(auto v : g[u]) if(pre[id[v]] && (!cut[v] || u<v)) addt(id[u], id[v]), pre[id[v]]=0;
            for(auto v : g[u]) pre[id[v]] = 1;
        }
    }
private:
    vector<int> pre, low;
    vector<pii> st;
    int n, clk = 0, chd=0, ct, a, b;
    void addt(int u, int v){
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

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

bcc.tree    -> graph of BlockCutTree
bcc.id[u]   -> componet of u in the tree
bcc.cut[u]  -> 1 if u is a cut vertex; 0 otherwise
bcc.comp[i] -> vertex of comp i (cut are part of multiple comp)
*****************************LATEX_DESC_END*/