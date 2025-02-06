#include <bits/stdc++.h>
#define endl "\n"
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
 
int main() {
    
    optimize;

    int casos;
    cin>>casos;
    stack <int> pilha;
    
    while (casos--)
    {
        string comando;
        cin>>comando;
        int aux = 0;

        if(comando == "PUSH"){
            cin>>aux;
            if( pilha.empty() ){ pilha.push(aux); } else 
            if(pilha.top()>aux){ pilha.push(aux); } else
                               { pilha.push(pilha.top()); }
            continue;
        }

        if(comando == "POP"){
            if(!pilha.empty()){
                pilha.pop();
            } else {
                cout<<"EMPTY"<<endl;
            }
            continue;
        }

        if(comando == "MIN" && !pilha.empty()){
            cout<<pilha.top()<<endl;
        } else  if(comando == "MIN" && pilha.empty()){
            cout<<"EMPTY"<<endl;
        }

        
    }
    
    
    return (0);
}