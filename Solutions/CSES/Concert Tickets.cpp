#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1090

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n, m;
    cin >> n >> m;

    multiset<int> st;
    for(int i=0, x; i<n && cin >> x; i++) st.emplace(x);

    for(int i=0, x; i<m && cin >> x; i++)
    {
        auto it = st.upper_bound(x);

        if(it == st.begin()) cout << -1 << '\n';
        else cout << *(--it) << '\n', st.erase(it);
    }

	return 0;	
}
