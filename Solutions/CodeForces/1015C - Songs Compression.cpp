#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>

//https://codeforces.com/problemset/problem/1015/C

int main(){

    ll n, m, sum = 0;
    cin >> n >> m;

    vi dif(n);

    for(int i=0, a, b; i<n; i++)
    {
        cin >> a >> b;
        dif[i] = a - b;
        sum += a;
    }

    int resp=0;
    sort(dif.begin(), dif.end(), greater<int>());

    while(sum > m && resp < n){
        sum -= dif[resp];
        resp++;
    }

    if(sum > m) resp = -1;

    cout << resp << endl;

    return 0;
}