#include <bits/stdc++.h>
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
