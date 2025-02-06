#include <bits/stdc++.h>
using namespace std;


int caixas[110][110];
int dp[110][110];

int peso(int linha, int coluna){

    if(dp[linha][coluna] != -1 ) return dp[linha][coluna];
    if(linha==0) return caixas[linha][coluna];

    int soma=0;
    for(int i=0; i<=linha; i++)
        soma+=caixas[linha][coluna+i];

    return dp[linha][coluna] = soma + min(peso(linha- 1, coluna), peso(linha- 1, coluna+ 1));

}
 
int main() {
    int qn; cin>>qn;

    for(int i=0; i<qn; i++){
        for(int e=0; e<qn; e++){
            cin>>caixas[i][e];
            dp[i][e] = -1;
        }
    }

    cout<<peso(qn- 1, 0)<<endl;
    
    
    return (0);
}

//https://olimpiada.ic.unicamp.br/pratique/p1/2018/f1/piramide/