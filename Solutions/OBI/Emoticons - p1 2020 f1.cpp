#include <iostream>
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p1/2020/f1/emoticons/

int main() {
 
    string text;
    getline(cin, text);

    int div=0; int chat=0;

    for(int i=0; i<(text.length() - 2); i++){
        if(text[i]==':' && text[i+ 1]=='-' && text[i+ 2]==')'){
            div++;
        } else if(text[i]==':' && text[i+ 1]=='-' && text[i+ 2]=='('){
            chat++;
        }
    }

    if(div>chat){ cout<<"divertido"; } else 
    if(div<chat){ cout<<"chateado";  } else
                { cout<<"neutro";    }
 
    return (0);
}