#include <bits/stdc++.h>
using namespace std;

struct Dice {
    int topo=6, norte=4, leste=5;
    
    int top()   { return topo; }
    int north() { return norte; }
    int east()  { return leste; }
    int bottom(){ return 7 - topo; }
    int south() { return 7 - norte; }
    int west()  { return 7 - leste; }

    void roll_north(){ tie(topo, norte) = pair(south(), top());  }
    void roll_east( ){ tie(topo, leste) = pair(west(),  top());  }
    void rotate_ccw(){ tie(norte,leste) = pair(east(),south());  }
    void roll_south(){ roll_north(); roll_north(); roll_north(); }
    void roll_west( ){ roll_east();  roll_east();  roll_east();  }
    void rotate_cw (){ rotate_ccw(); rotate_ccw(); rotate_ccw(); }

    int get_id(){ //[0, 23]
        int id = (topo-1)^(norte-1);
        id %= topo==3||topo==4 ? 6 : 4;
        return topo*4 + id - 4;
    }
};

/*LATEX_DESC_BEGIN***************************
   Dadinho de 6 lados     |   |4|       ^ norte
24 estados possiveis      | |2|6|5| w < + > leste
Assume que a soma de lados|   |3|       v 
opostos é 7.              |   |1|      sul
Se precisar de labels diferentes, crie um
 array<int, 7> face = {0, 1, 2, 3, 4, 5, 6}
e acesse a posição da face retornada.
*****************************LATEX_DESC_END*/