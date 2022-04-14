#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string novaJoia = "";
    vector <string> tipos(1);

    while(cin>>novaJoia){

        for (int i = 0; i < tipos.size(); i++){
            if(tipos[i]==novaJoia){
                break;
            } else if(i == (tipos.size() - 1)){
                tipos.push_back(novaJoia);
            }
        }
    
    }

    cout<<(tipos.size() - 1)<<endl;
    
    return (0);
}