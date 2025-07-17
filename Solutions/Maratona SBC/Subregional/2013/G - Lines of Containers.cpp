#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

const int MAXN = 305;
int mat[MAXN][MAXN];
int n, m;

void swap_col(int a, int b){
    for(int i=0; i<n; i++)
        swap(mat[i][a], mat[i][b]);
}
void swap_lin(int a, int b){
    for(int j=0; j<m; j++)
        swap(mat[a][j], mat[b][j]);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> mat[i][j], mat[i][j]--;

    int ans = 0;

    for(int i=0; i<n; i++)
        while(mat[i][0]/m != i && ans <= (n+m))
            swap_lin(i, mat[i][0]/m), 
            ans++;
    
    for(int j=0; j<m; j++)
        while(mat[0][j]%m != j && ans <= (n+m))
            swap_col(j, mat[0][j]%m),
            ans++;
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(mat[i][j] != i*m + j)
                ans = -1;
            
    if(~ans) cout << ans << endl;
    else cout << "*\n";
}
