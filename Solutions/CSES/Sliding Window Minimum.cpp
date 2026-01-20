#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct MinQueue : deque<pair<int, int>> {
    int min(){ return front().first; }
    void push(int x){
        int cnt = 1;
        while(!empty() && x <= back().first) 
            cnt += back().second, pop_back();
        push_back({x, cnt});
    }
    void pop(){ if(!--front().second) pop_front(); }
};

int main(){

    int n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    
    MinQueue mq;

    for(int i=0; i<k; i++){
        mq.push(x);
        x = (x*a + b) % c;
    }
    
    int ans = mq.min();

    for(int i=k; i<n; i++){
        mq.push(x);
        mq.pop();
        ans ^= mq.min();
        x = (x*a + b) % c;
    }
    
    cout << ans << endl;
}