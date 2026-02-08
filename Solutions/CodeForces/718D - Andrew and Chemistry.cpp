#include <bits/stdc++.h>
#define ll long long
using namespace std;
// tree hash
//  DONT USE POLYNOMIAL HASH!!!
const ll MAXN  =  1e5 + 10;
const ll mod   = 998244353;
const ll FOLHA =      2343;
const ll base  = 1e5 + 5223;

ll hashval[MAXN];
vector<int> g[MAXN];
vector<ll> sla;

ll get_hsh(ll u, ll ignored){

    vector<ll> chd;
    for(auto v : g[u])
        if(v != ignored)
            chd.push_back(hashval[v]);
    
    sort(begin(chd), end(chd));
    
    if(chd.empty()) return FOLHA;

    ll hsh = 0;
    ll pot = base;
    for(auto x : chd) hsh += x*x + pot * x, pot *= base;

    return hsh;
}

void dfs(int u, int p){
    for(auto v : g[u]) 
        if(v != p)
            dfs(v, u);
    
    hashval[u] = get_hsh(u, p);
}

void solve(int u, int p){    
 
    ll oldhsh = hashval[u];

    // assumindo que meu pai tá com o valor de hash atualizado
    // como se não tivesse aresta pra mim
    if(g[u].size() < 4){
        sla.push_back(get_hsh(u, -1)); //não ignora ninguém (é a raiz atual)
        // cout << u+1 << "u hsh: " << sla.back() << " | ";
        // for(auto v : g[u]) cout << hashval[v] << " "; cout << endl;
    }

    // vou pra cada filho, atualizando meu valor pra ignorar ele
    for(auto v : g[u]) if(v != p){
        hashval[u] = get_hsh(u, v);
        solve(v, u);
    }

    hashval[u] = oldhsh;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;

    for(int i=1, u, v; i<n; i++){
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0);
    solve(0, 0);

    sort(begin(sla), end(sla));
    sla.resize(unique(sla.begin(), sla.end()) - sla.begin());

    cout << sla.size() << endl;
}