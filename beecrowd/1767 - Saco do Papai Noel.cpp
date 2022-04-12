#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define piii pair<int, pii>
#define pct first
#define pes second
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
int qtd;
piii mem [51][100];
bool memo[51][100];
pii pacote[110];

int pesoFinal;

piii saco(int peso, int atual){
    if(peso > 50)         return {-100000, {0, 0}};
    if(atual == qtd)      return {0, {0, 0}};
    if(memo[peso][atual]) return mem[peso][atual];
    else memo[peso][atual] = true;
       
    auto sem = saco(peso, atual+1);
    
    auto com = saco(peso + pacote[atual].second, atual+1);
    com.first        += pacote[atual].first;  //qtd de presentes
    com.second.first += 1;                    //qtd de pacotes
    com.second.second+= pacote[atual].second; //peso

    return mem[peso][atual] = max(sem, com);
}


int main() {
    optimize;

    int casos; cin>>casos;

    for(int i=0; i<casos; i++){
        memset(memo, false,      sizeof memo);

         cin>> qtd;

        for(int e=0; e<qtd; e++){
            int qt, peso;
            cin>>qt>>peso;
            pacote[e] = {qt, peso};
        }

        auto resp = saco(0, 0);

        int brinq   = resp.first;
        int pacotes = resp.second.first;
        int peso    = resp.second.second;

        cout<<brinq<<" brinquedos"<<endl;
        cout<<"Peso: "<<peso<<" kg"<<endl;
        cout<<"sobra(m) "<<qtd - pacotes<<" pacote(s)"<<endl<<endl;
    }
 
    return (0);
}