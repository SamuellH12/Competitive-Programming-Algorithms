#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m, ist;
    cin >> n >> m >> ist;

    vector<int> age(n);
    for(auto &x : age) cin >> x;

    vector<vector<int>> g(n);
    vector<int> gin(n, 0), roots;

    for(int i=0, u, v; i<m; i++){
       cin >> u >> v;
       u--, v--;
       g[u].emplace_back(v);
       gin[v]++;
    }
    vector<int> atual(n);
    for(int i=0; i<n; i++) atual[i] = i;

    for(int i=0; i<n; i++) roots.emplace_back(i);

    vector<int> vis;
    function<void(int, int)> dfs = [&](int u, int a){
        if(vis[u] <= a) return;
        vis[u] = a;
        a = min(a, age[u]);

        for(auto v : g[u])
            dfs(v, a);
    };
    sort(begin(roots), end(roots), [&](int u, int v){ return age[u] < age[v]; });

    auto update = [&](){
        vis.assign(n, 1e9+7);
        for(auto x : roots) dfs(atual[x], 1e9);
    };
    update();
    
    char op;
    int u, v;
    while(ist--)
    {
        cin >> op;
        if(op == 'P'){
            cin >> u; u--;
            u = atual[u];
            if(vis[u] < 1e8) cout << vis[u] << endl;
            else cout << "*" << endl;
        }
        else 
        {
            cin >> u >> v; 
            u--, v--;
            swap(atual[u], atual[v]);
            u = atual[u]; v = atual[v];
            swap(age[u], age[v]);
            update();
        }
    }

}
