#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
    string pais[] = {"brasil", "alemanha","austria","coreia","espanha","grecia","estados-unidos",
    "inglaterra","australia","portugal","suecia","turquia","argentina","chile","mexico","antardida",
    "canada","irlanda","belgica","italia","libia","siria","marrocos","japao" };
    
    string feliz[] = {"Feliz Natal!","Frohliche Weihnachten!","Frohe Weihnacht!","Chuk Sung Tan!","Feliz Navidad!",
    "Kala Christougena!","Merry Christmas!","Merry Christmas!","Merry Christmas!","Feliz Natal!","God Jul!","Mutlu Noeller",
    "Feliz Navidad!","Feliz Navidad!","Feliz Navidad!","Merry Christmas!","Merry Christmas!","Nollaig Shona Dhuit!",
    "Zalig Kerstfeest!","Buon Natale!","Buon Natale!","Milad Mubarak!","Milad Mubarak!","Merii Kurisumasu!"};

    string atual = "";

    while (cin>>atual)
    {
        for (int i = 0; i < 24; i++){
            if(atual == pais[i]){
                cout<<feliz[i]<<endl;
                break;
            } else if( i == 23 ){
                cout<<"--- NOT FOUND ---"<<endl;
            }
        }
    }
    

    return (0);
}