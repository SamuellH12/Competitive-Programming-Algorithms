#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int>>
#define ll long long
#define MAXN 105

// B. Marbles
// https://codeforces.com/gym/101908/problem/B

int version = 0;
int used[MAXN * MAXN];

int mex(){
    for(int i=0; ; i++)
        if(used[i] != version) 
            return i;
}

int grid[MAXN][MAXN];

void init(int x, int y){
    if(x == y || !x || !y) return;
    version++;

    for(int i=x-1; i>0; i--) if(i != y) used[grid[i][y]] = version; 
    for(int i=y-1; i>0; i--) if(x != i) used[grid[x][i]] = version; 
    for(int i=x-1, j=y-1; i>0 && j>0; i--, j--) used[grid[i][j]] = version; 

    grid[x][y] = mex() ;
}


int main(){

    for(int i=1; i<MAXN; i++){
        for(int j=1; j<MAXN; j++){
            init(i, j);
        }
    }

    int n; cin >> n;

    int resp = 0;

    for(int i=0, x, y; i<n; i++){
        cin >> x  >> y;
        resp ^= grid[x][y];

        if(x == 0 || y == 0 || x==y) 
        {
            cout << "Y" << endl;
            return 0;
        }
    }

    cout << (resp != 0? "Y" : "N") << endl;

    return 0;
}