#include <bits/stdc++.h>
using namespace std;

int capacidade, resistencia, qtd, poder[55], peso[55];

int    memoria  [110][55];
bool ja_calculou[110][55];


int castelo(int capacidade, int projAtual){

    if(capacidade < 0)      return  -10000000000;
    if(projAtual == qtd)    return 0;
   
    if( ja_calculou [capacidade] [projAtual] ) return memoria [capacidade] [projAtual];
    

    ja_calculou[capacidade][projAtual] = true;
    
    int comProj = castelo( (capacidade - peso[projAtual]), projAtual + 1 ) + poder[projAtual];
    int semProj = castelo(capacidade, (projAtual + 1));

    return memoria[capacidade][projAtual] = max(comProj, semProj);
}


 
int main() {

    int casos; cin>>casos;

    for(int i=0; i<casos; i++){

        memset(ja_calculou, false, sizeof ja_calculou);

         cin>> qtd;

        for(int e=0; e<qtd; e++){
            cin>>poder[e]>>peso[e];
        }

        cin>>capacidade>>resistencia;

        if( castelo(capacidade, 0) >= resistencia){ cout<< "Missao completada com sucesso"<< endl; }
        else { cout<< "Falha na missao"<< endl; }

    }
 
    return (0);
}