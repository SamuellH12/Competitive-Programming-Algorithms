#include <bits/stdc++.h>
using namespace std;
 
int main() {
 
    double a, b, c, d;
    cin>>a>>b>>c>>d;

    double m = ((a * 2) + (b * 3) + (c * 4) + d)/10;

    cout<<fixed<<setprecision(1)<<"Media: "<<m<<endl;

    if(m>=7){
        cout<<"Aluno aprovado."<<endl;
    } else if(m < 5){
        cout<<"Aluno reprovado."<<endl;
    } else {
        double e;
        cin>>e;
        cout<<"Aluno em exame."<<endl<<"Nota do exame: "<<e<<endl;
        if( (e+m)/2 < 5){
            cout<<"Aluno reprovado."<<endl;
        } else {
            cout<<"Aluno aprovado."<<endl;
        }
        cout<<"Media final: "<< (e+m)/2 <<endl;
    }

 
    return (0);
}