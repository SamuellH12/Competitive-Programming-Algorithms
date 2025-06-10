#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/2217

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n, m; 
    cin >> n >> m;

    vector<int> sla(n), sll(n);

    for(int i=0, x; i<n && cin >> x; i++)
        sla[x-1] = i, sll[i] = x-1;

    int ans = 1;

    vector<int> sh(n-1);
    for(int i=0; i+1<n; i++)
        ans += (sh[i] = sla[i] > sla[i+1]);

    int a, b, x, y;
    while(m--)
    {
        cin >> a >> b;
        a--, b--;

        x = sll[a];
        y = sll[b];

        set<int> change({x-1, x, y-1, y});

        sla[x] = b;
        sll[b] = x;
        sla[y] = a;
        sll[a] = y;
        
        
        for(auto i : change)
            if(i+1 < n && i>=0)
            {
                if( sh[i] && !(sla[i] > sla[i+1])) ans--;
                if(!sh[i] &&  (sla[i] > sla[i+1])) ans++;
                sh[i] = (sla[i] > sla[i+1]);
            }
        
        cout << ans << '\n';
    }

	return 0;	
}
