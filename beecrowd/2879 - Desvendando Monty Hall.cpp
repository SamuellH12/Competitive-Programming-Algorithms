#include <iostream>
using namespace std;
 
int main() {
 
    int testes;
    cin>>testes;
    int acertos=0;

    for (int i = 0; i < testes; i++)
    {
        int carro;
        cin>>carro;
        if(carro!=1){
            acertos++;
        }
    }
    
    cout<<acertos;

 
    return (0);
}