#include <bits/stdc++.h>
#define ll long long
using namespace std;
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1895

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while(cin >> n && n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0, x; i<n; i++)
        {
            cin >> x;
            pq.push(x);
        }

        int custo = 0;	

        while( pq.size() >= 2 )
        {
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            custo += x + y;
            pq.push(x+y);
        }

        cout << custo << endl;
    }


    return 0;	
}
