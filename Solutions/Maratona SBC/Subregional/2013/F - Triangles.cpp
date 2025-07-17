#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> sla(n+1);
    for(int i=1; i<=n; i++) cin >> sla[i], sla[i] += sla[i-1];

    int ans = 0;

    if(sla.back() % 3){
        cout << 0 << endl;
        return 0;
    }

    int lado = sla.back() / 3;

    for(int i=0; i<n; i++){
        if(sla[i] >= lado) break;

        bool ok = true;

        auto   it = lower_bound(begin(sla), end(sla), sla[i] + lado);
        if(it == sla.end() || *it != sla[i] + lado) ok = false;
        
        if(ok) it = lower_bound(begin(sla), end(sla), sla[i] + lado + lado);
        if(it == sla.end() || *it != sla[i] + lado + lado) ok = false;

        ans += ok;
    }

    cout << ans << endl;
}
