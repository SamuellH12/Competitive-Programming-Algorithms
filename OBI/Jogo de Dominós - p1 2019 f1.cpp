#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
    int n; cin>>n;

    int p = 0;

    for(int i=1; i<=(n + 1); i++)
        p += i;

    cout<<p<<endl;

    return (0);
}


/*

    SOLUÇÃO POSTADA PELA OBI:

    cout<<((p+1)*(p+2))/2 << endl;

    É... BEEEEEM MAIS SIMPLES DO QUE EU PODERIA IMAGINAR, BEM, 
    É MAIS UMA QUESTÃO DE VOCÊ ENTENDER DE MATEMÁTICA, MAS OK
    MEU CÓDIGO FUNCIONA.
    
*/