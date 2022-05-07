#include <iostream>
using namespace std;
 
int main() {
 
     int namigos, nreunioes, infec, reun1doen;
    cin>>namigos>>nreunioes>>infec>>reun1doen;
    int infs[namigos] = {}; infs[infec- 1]=infec;

    for(int i=1; i<=nreunioes; i++){

        int qpresentes; cin>>qpresentes;
        int presentes[qpresentes] = {};
        for(int a=0; a<qpresentes; a++){ cin>>presentes[a];}

        if(i>=reun1doen){

            bool cont = false; 
            for(int a=0; a<qpresentes; a++){

                for(int b=0; b<namigos; b++){
                    if(cont){ break; }
                    if(infs[b]==presentes[a]){ cont=true; break;}
                }

                if(cont){
                    for(int c=0; c<qpresentes; c++){
                        infs[(presentes[c]- 1)]=presentes[c];
                    }
                    break;
                }
            }
        }
    }

    int totalDeInfc = 0;
    for(int c=0; c<namigos; c++){
        if(infs[c] != 0){
            totalDeInfc++;
        }
    }

    cout<<totalDeInfc;
 
    return (0);
}