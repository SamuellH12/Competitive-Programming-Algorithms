#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
int main() {
    
    optimize;
 
    int npalavras, ndescr;
    cin>>npalavras>>ndescr;

    unordered_map <string, int> plvr_sal;

    for(int i=0; i < npalavras; i++){
        string chave; int partSal;
        cin>>chave>>partSal;
        plvr_sal[chave] = partSal;
    }

    while ( ndescr-- ){
        int salTotal = 0;
        string analise;

        while ((cin>>analise) && analise != "."){
            salTotal += plvr_sal[analise];
        }

        cout<<salTotal<<endl;

    }
    
    
    
    return (0);
}
