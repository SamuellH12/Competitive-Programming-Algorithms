#include <bits/stdc++.h>

#define ll long long
#define br '\n'

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


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

int n, m;
int grid[102][102];
bool valid(int x, int y){
    return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != -1;
}


int sx, sy;
int w = 0;
bool got[102][102];
bool seen[102][102][24];

void dfs(int x, int y, Dice d){
    if(seen[x][y][d.get_id()]) return;
    seen[x][y][d.get_id()] = 1;
    if(!got[x][y] && d.top() == grid[x][y]) got[x][y] = ++w;

    { // cima
        int ax = x - 1, ay = y;
        d.roll_north();
        if(valid(ax,ay)) dfs(ax,ay, d);        
        d.roll_south();
    }

    { // BAIXO
        int ax = x + 1, ay = y;
        d.roll_south();
        if(valid(ax,ay)) dfs(ax,ay, d);   
        d.roll_north();
    }
    { // left
        int ax = x, ay = y-1;
        d.roll_west();
        if(valid(ax,ay)) dfs(ax,ay, d);   
        d.roll_east();
    }
    { // right
        int ax = x, ay = y+1;
        d.roll_east();
        if(valid(ax,ay)) dfs(ax,ay, d);
        d.roll_west();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c; cin >> c;
            if(c == 's'){ sx = i, sy = j; continue; }
            if(c == '.') continue;
            if(c == 'x'){ grid[i][j] = -1; continue; }
            grid[i][j] = (c-'0');
        }
    }
    Dice d;
    dfs(sx,sy, d);
    cout << w << br;    
}   