#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
    int m, f1, f2, f3;

    cin>>m>>f1>>f2;

    f3 = m - f1 - f2;

    f1 = max(f1, f3);

    cout<<max(f1, f2);
     
    return (0);
}