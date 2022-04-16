#include <iostream>
using namespace std;
 
int main() {
 
    int c1, c2, c3;
    cin>>c1>>c2>>c3;

    if((c2-c1) > (c3-c2)){
        cout<<-1;
    } else if((c2-c1) < (c3-c2)){
        cout<<1;
    } else {
        cout<<0;
    }

    return (0);
}