#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//https://olimpiada.ic.unicamp.br/pratique/p2/2020/f1/fissura/

char mapa[550][550];
 
int main() {
 
    int l; char f; 
    cin>>l>>f;

    for(int x=0; x<l; x++){
        for(int y=0; y<l; y++){
            cin>>mapa[x][y];
        }
    }

    stack< pair<int, int> > verixy;
    verixy.push({0, 0});


    while ( !verixy.empty())
    {
        pair <int, int> xy = verixy.top();

        int x = xy.first; int y = xy.second;

        if(mapa [x][y] <= f && mapa [x][y] != '*'){

            mapa [x] [y] = '*';
            verixy.pop();

            if(x > 0 && mapa [x- 1] [y] != '*' && mapa [x- 1] [y] <=f){
                verixy.push( {x - 1, y} );
            }
            if(y > 0 && mapa [x] [y- 1] != '*' && mapa [x] [y- 1] <=f){
                verixy.push( {x, y - 1} );
            }
            if(x < (l - 1) && mapa [x+ 1] [y] != '*' && mapa [x+ 1] [y] <=f){
                verixy.push( {x + 1, y } );
            }
            if(y < (l - 1) && mapa [x] [y+ 1] != '*' && mapa [x] [y+ 1] <=f){
                verixy.push( {x, y + 1} );
            }

         } else { verixy.pop(); }

    }

    
    for(int x=0; x<l; x++){
        for(int y=0; y<l; y++){
            cout << mapa[x][y];
        }
        cout << endl;
    }
    
    
    return (0);
}