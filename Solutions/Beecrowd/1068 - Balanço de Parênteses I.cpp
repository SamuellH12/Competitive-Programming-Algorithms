#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string equa = "";

while(cin>>equa){

    if(equa[0] == '\0'){break;}

    bool correto = true;
    stack <char> pilha;

    for(int i=0; i<equa.length(); i++){
        
        if(equa[i]=='('){
            pilha.push(equa[i]);
        } else if(equa[i] == ')' && pilha.size() == 0 ){
            correto = false;
            break;
        } else if(equa[i]==')' && pilha.top()=='('){
            pilha.pop();
        }

    }

    if(correto && pilha.size()>0){
        correto = false;
    }

    if(correto){
        cout<<"correct"<<endl;
    } 
    if(!correto){
        cout<<"incorrect"<<endl;
    }
}
    
    return (0);
}