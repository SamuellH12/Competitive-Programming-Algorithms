#include <bits/stdc++.h>
#define endl "\n"
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

string pri, sec;

int verif( int I, int E){

    int maiorRept = 0;

    for(int a=0; a + I < pri.length() && a + E < sec.length(); a++){
        
        if( pri[a + I] == sec[a + E]){
            maiorRept = a + 1;
        } else {
            break;
        }

    }

    return (maiorRept);
}

int main() {

    while(getline(cin, pri)){

        getline(cin, sec);

        int maior=0;

        for(int i=0; i<pri.length(); i++){
            for(int e=0; e<sec.length(); e++){

                int veri = verif(i , e);
                if(veri > maior){ maior = veri; }
            }
        }

        cout<<maior<<endl;

    }
    
    return (0);
}

