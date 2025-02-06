#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define ll long long
#define sc second
#define ft first
using namespace std;

#define debug cout<<"ate aqui ok\n"

string a, b;
int casos;

bool aparicoes(int n){

    int pos_a = 0;

    for(auto B : b){
        for(int qtd=0; qtd < n; qtd++){

            while( pos_a < a.size() && B != a[pos_a] )
                pos_a++;
            
            if( pos_a == a.size())
                return false;

            pos_a++;
        }
    }

    return true;
}


int main(){

    optimize;
	
    cin>>casos;

    while(casos--){
        
        cin>>a>>b;

        int esq = 0, dir = a.size() / b.size(), maiorValor;

        while( esq <= dir ){

            int meio = (esq + dir) / 2;

            if( aparicoes(meio) ){
                maiorValor = meio;
                esq = meio + 1;
            } else {
                dir = meio - 1;
            }

        }

        cout<<maiorValor<<endl;

    }

	return 0;	
}