#include <iostream>
using namespace std;
 
int main() {
    int fandar1, fandar2, fandar3;
    cin>>fandar1;
    cin>>fandar2;
    cin>>fandar3;
    int andar1, andar2, andar3;

    andar1 = (fandar2*2)+(fandar3*4);
    andar2 = (fandar1*2)+(fandar3*2);
    andar3 = (fandar2*2)+(fandar1*4);

    if(andar1<=andar2 && andar1<=andar3){
        cout<<andar1<<endl;
    } else if(andar2<=andar1 && andar2<=andar3){
        cout<<andar2<<endl;
    } else {
        cout<<andar3<<endl;
    }
 
    return (0);
}