#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int casos;
    cin>>casos;
    
    for(int a=0; a<casos; a++){

        stack <char> pilha;
        
        string mina;
        cin>>mina;

        int qdima=0;

        for(int i=0; i<mina.length(); i++){
            
            if(mina[i]=='<'){
                pilha.push(mina[i]);

            } else if(mina[i] == '>' && pilha.size() == 0 ){

            } else if(mina[i]=='>' && pilha.top()=='<'){
                    pilha.pop();
                    qdima++;
            }

        }

    cout<<qdima;

    
}
    
    return (0);
}