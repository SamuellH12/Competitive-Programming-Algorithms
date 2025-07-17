#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define endl "\n"
using namespace std;

vector<int> ans;
set<vi> memo;

//  ##|###

vi fold(vi &sla, int i){
    int n = sla.size();
    int m = max(n-i, i);
    vi res(m, 0);

    if(i+i>=n) // começo é o começo
    {
        for(int j=0; j<i; j++) res[j]   += sla[j];
        for(int j=i; j<n; j++) res[j-i] += sla[j];
    }
    else 
    {
        int d = n-i-i;
        for(int j=0; j<i; j++) res[d+j] += sla[j];
        for(int j=i; j<n; j++) res[m-j+i-1] += sla[j];
    }

    return res;
}

bool solve(vector<int> sla){
    if(sla == ans) return true;
    if(sla.size() < ans.size()) return false;

    for(int i=0; i<sla.size(); i++){
        vi at = fold(sla, i);
        if(memo.count(at)) continue;
        memo.insert(at);
        if(solve(at)) return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    
    cin >> n;
    vi sla(n);
    for(auto &x : sla) cin >> x;

    cin >> m;
    ans.resize(m);
    for(auto &x : ans) cin >> x;

    if(accumulate(begin(sla), end(sla), 0LL) != accumulate(begin(ans), end(ans), 0LL)){
        cout << "N\n";
        return 0;
    }

    cout << "NS"[solve(sla)] << endl;
}
