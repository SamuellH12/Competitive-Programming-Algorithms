#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/2216

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n; cin >> n;

    vector<int> sla(n);

    for(int i=0, x; i<n && cin >> x; i++)
        sla[x-1] = i;

    if(n == 1){
        cout << 1 << '\n';
        return 0;
    }

    int ans = 1;

    for(int i=0; i+1<n; i++)
        ans += (sla[i] > sla[i+1]);

    cout << ans << '\n';

	return 0;	
}
