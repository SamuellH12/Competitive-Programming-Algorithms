#include <bits/stdc++.h>
using namespace std;
#define ll long long

//https://codeforces.com/problemset/problem/1077/A

int main(){

    int t;
    cin >> t;

    while(t--)
    {
        ll a, b, k;
        cin >> a >> b >> k;

        ll resp = 0;

        if(k%2){
            resp = (k/2 + 1) * a - (k/2)*b;
        }
        else resp = (k/2) * a - (k/2)*b;
        

        cout << resp << endl;

    }

    return 0;
}