#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
int main() {
    
    string cifra, chave;
    cin>>cifra>>chave;
    
    int possiveis = 0;

    for(int a=0; a <= (cifra.length() - chave.length()); a++){
        bool achou = false;

        for(int e=0; e<chave.length(); e++){

            if(chave[e] == cifra[e + a]){
                achou = true;
                break;
            }

        }
        
        if(!achou){ possiveis++; }

    }

    cout<<possiveis<<endl;
    
    
    return (0);
}
