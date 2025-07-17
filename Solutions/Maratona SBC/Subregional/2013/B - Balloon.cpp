#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

struct seg {
    int x1, y1, x2, y2, i;
    seg(){}
    void fix(){
        if(x1 < x2) return;
        swap(x1, x2);
        swap(y1, y2);
    }
    bool operator<(seg &b){ return max(y1, y2) < max(b.y1, b.y2);  }
};
#define pii pair<int, int>


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<seg> sla(n+m);

    for(int i=0; i<n; i++)
    {
        sla[i].i = i;
        cin >> sla[i].x1 >> sla[i].y1 >> sla[i].x2 >> sla[i].y2;
        sla[i].fix();
    }

    for(int j=0; j<m; j++)
    {
        sla[j+n].i = ~j;
        cin >> sla[j+n].x1;
        sla[j+n].y1 = 0;
        sla[j+n].y2 = -1;
        sla[j+n].x2 = sla[j+n].x1;
    }

    auto orig = sla;
    sort(begin(sla), end(sla));

    vector<int> aresta(n+m, -1);
    set<pii> ativos;

    for(auto at : sla)
    {   
        auto [x1, y1, x2, y2, i] = at;

        if(i < 0) i = (~i) + n;

        auto it = ativos.lower_bound(pii(x1, numeric_limits<int>::min()));

        while(it != ativos.end())
        {
            if(it->first > x2 ) break; //passa direto ou entra?
            aresta[it->second] = i;
            it = ativos.erase(it);
        }

        if(y1 == y2) continue;

        if(y1 > y2) ativos.insert(pii(x1, i));
        else ativos.insert(pii(x2, i));
    }
    
    for(auto [x, i] : ativos)
        aresta[i] = -2;

    vector<int> xend(n+m, -100), yend(n+m, -100);

    function<pii(int)> solve = [&](int u){
        if(xend[u] != -100) return pii(xend[u], yend[u]);
        if(aresta[u] == -1) return pii( -2, orig[u].y1); //flat
        if(aresta[u] == -2) return pii( orig[u].y1 > orig[u].y2 ?  orig[u].x1 : orig[u].x2 , -1); //inf
        
        auto s = solve(aresta[u]);
        if(s.first == -2) s.first = orig[u].y1 > orig[u].y2 ?  orig[u].x1 : orig[u].x2;
        return s;
    };

    for(int i=0; i<m ; i++)
    {
        auto [x, y] = solve(i+n);
        cout << x;
        if(y > 0) cout << " " << y;
        cout << endl;
    }
}