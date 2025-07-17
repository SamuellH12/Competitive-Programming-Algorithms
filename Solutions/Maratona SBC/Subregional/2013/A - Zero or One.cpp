#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b, c;
    cin >> a >> b >> c;

    if(a != b && a != c) cout << "A\n";
    else 
    if(a != b && b != c) cout << "B\n";
    else
    if(a != c && b != c) cout << "C\n";
    else 
        cout << "*\n";
}
