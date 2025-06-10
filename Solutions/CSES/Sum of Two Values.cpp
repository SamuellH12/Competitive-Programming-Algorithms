#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1090

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n, x;
    cin >> n >> x;
    
    map<int, int> mp;

    bool ok = false;

    for(int i=0, a; i<n && cin >> a; i++)
    {        
        if(!ok && mp.count(x-a))
            cout << mp[x-a]+1 << ' ' << i+1 << '\n', ok = true;

        if(!ok) mp[a] = i;
    }

    if(!ok) cout << "IMPOSSIBLE\n";

	return 0;	
}
