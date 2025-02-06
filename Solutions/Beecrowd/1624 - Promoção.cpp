#include <bits/stdc++.h>
using namespace std;

int pesoMax, preco[110], peso[110], nlista;

int dp[3030][3030];
bool dpb[3030][3030];

int produtos(int pesoAtual, int analiz){

    if( pesoAtual > pesoMax) return -10000000;
    if(analiz == nlista) return 0;

    if(dpb[pesoAtual][analiz]) return dp[pesoAtual][analiz];
    
    int pega = produtos(pesoAtual + peso[analiz], analiz + 1) + preco[analiz];
    int npega= produtos(pesoAtual, analiz + 1);

    dpb[pesoAtual][analiz] = true;

    return dp[pesoAtual][analiz] = max(pega, npega);
}
 
int main() {
    
    int n;

    while (cin>>n && n != 0){

        memset(dpb, false, sizeof dpb);
        
        nlista = n;

        for(int i=0; i<nlista; i++){
            cin>>preco[i]>>peso[i];
        }

        cin>>pesoMax;

        cout<<produtos(0, 0)<<endl;

    }
    

    
    return (0);
}