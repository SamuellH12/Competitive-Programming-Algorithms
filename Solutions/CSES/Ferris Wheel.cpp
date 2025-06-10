#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1090

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n, x;
    cin >> n >> x;
    
    multiset<int> st;

    for(int i=0, x; i<n && cin >> x; i++) 
        st.emplace(x);

    int ans = 0;

    while(!st.empty())
    {
        int p = *(--st.end());
        st.erase(--st.end());
        
        auto it = st.upper_bound(x-p);

        if(it != st.begin())
            st.erase(--it);
        
        ans++;
    }

    cout << ans << '\n';

	return 0;	
}
