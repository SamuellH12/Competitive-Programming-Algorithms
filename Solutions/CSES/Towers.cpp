#include <bits/stdc++.h>
using namespace std;
// https://cses.fi/problemset/task/1073

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL);
	
    int n; cin >> n;

    vector<int> tow;

    for(int i=0, x; i<n; i++)
    {
        cin >> x;
        auto it = upper_bound(begin(tow), end(tow), x);
        if(it == end(tow)) tow.emplace_back(x);
        else *it = x;
    }

    cout << tow.size() << '\n';

	return 0;	
}
