#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
    int idas;
    cin>>idas;

    for (int a = 0; a < idas; a++){
        int disp, comp;

        cin>>disp;
        string prod[disp]; double prec[disp];

        for(int i=0; i<disp; i++){
            cin>>prod[i]>>prec[i];
        }

        cin>>comp;
        string cest[comp]; int quan[comp];

        for(int i=0; i<comp; i++){
            cin>>cest[i]>>quan[i];
        }

        double total = 0;

        for (int i = 0; i < comp; i++){
            for(int e=0; e<disp; e++){
                if(cest[i]==prod[e]){
                    total += (prec[e] * quan[i]);
                    break;
                }
            }
        }
        cout<<fixed<<setprecision(2);
        cout<<"R$ "<<total<<endl;

    }

    return (0);
}