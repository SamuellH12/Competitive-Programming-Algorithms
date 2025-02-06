#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
    int b, t;
    cin>>b>>t;

    int areanotametade = 11200 / 2;

    int areaA = ((b + t) / 2 ) * 70;

    if(areaA == areanotametade) cout<<0<<endl;
    else if( areaA > areanotametade ) cout<<1<<endl;
    else cout<<2<<endl;


    return (0);
}