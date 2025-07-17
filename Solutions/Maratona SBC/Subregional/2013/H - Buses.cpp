#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

ll mod = 1e6;

struct matrix {
    vector<vector<ll>> mat;

    matrix(int n) : mat(n, vector<ll>(n, 0)) {}

    matrix operator* (const matrix& b) const {
        int n = mat.size();
        matrix ans(n);

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    ans.mat[i][j] += mat[i][k] * b.mat[k][j] % mod,
                    ans.mat[i][j] %= mod;

        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    ll n, k, l;
    cin >> n >> k >> l;

    n /= 5;  
    k %= mod;
    l %= mod;

    matrix m(2), ans(2);

    m.mat ={{k, l},
            {1, 0}};
    
    ans.mat={{1, 0},
             {0, 1}};

    while(n){
        if(n&1) ans = ans * m;
        m = m*m;
        n >>= 1;
    }

    ll res = ans.mat[0][0];
    string resp = "";
    for(int i=6; i--; res /= 10) resp += '0' + res%10;
    reverse(begin(resp), end(resp));
    cout << resp << endl;
}
