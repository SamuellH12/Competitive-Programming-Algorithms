#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1629

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n; cin >> n;
    
    vector<pair<int, int>> sla;

    for(int i=0, b, e; i<n; i++){
        cin >> b >> e;
        sla.emplace_back(e, b);
    }

    sort(begin(sla), end(sla));

    int ans = 0, lst=-1;

    for(auto [e, b] : sla)
        if(lst <= b) 
            lst = e,   
            ans++;

    cout << ans << '\n';

	return 0;	
}
