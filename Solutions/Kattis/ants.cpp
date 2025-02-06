#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()

//https://open.kattis.com/problems/ants

int main(){

    int t, l, n; cin >> t;

    while(t--)
    {
        cin >> l >> n;

        int b=0, s=999999, sf=-1;

        for(int i=0, f; i<n; i++)
        {
            cin >> f;
            b = max({b, f, l-f});   //pega a formiga mais distante de uma ponta qualquer
            
            if( s > abs( f - abs(l-f)) ){   //pega a formiga que tá mais perto do meio
                s = abs( f - abs(l-f));
                sf = f;
            }
        }

        cout << min(sf, l-sf) << " " << b  << endl;

    }

}