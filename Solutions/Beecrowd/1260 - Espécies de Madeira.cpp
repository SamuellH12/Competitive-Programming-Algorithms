#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
using namespace std;
 
int main() {
    optimize;
    cout<<fixed<<setprecision(4);
    int casos; string plant;
    cin>>casos; getline(cin, plant);

    int primeiro = 0;
    casos++;

    while(casos--){
        if(primeiro > 1) cout<<endl;

        int qtdAveri=0;
        map <string, int> arvores;

        while(getline(cin, plant)){
            if(plant=="") break;
            arvores[plant]++;
            qtdAveri++;
        }

        for(auto averi : arvores)
            cout<<averi.first<<" "<< ((double) averi.second / qtdAveri * 100)<<endl;

        primeiro++;
    }
    
    return (0);
}