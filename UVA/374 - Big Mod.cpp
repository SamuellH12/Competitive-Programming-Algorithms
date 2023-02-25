#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=310
//https://vjudge.net/contest/539684#problem/F

//exponiação rápida (não sei ainda fazer, tava na biblioteca do Carlos e do Lucas)
//versão iterativa
ll fexp(ll b, ll p, ll mod)
{
    ll resp = 1;

    while(p){
        if(p & 1) resp =( resp * b) % mod; //se potencia E impar, resp *= base
        b = b * b % mod;    // elevo a base ao quadrado
        p = p >> 1;     //e divido a potencia por 2
    }

    return resp;
}


// AGORA ENTENDI!!! Fast Exp recursiva: basicamente, vou dividindo por 2 enquanto
// possível a potência e utilizo isso pra fazer todas as operações em log!
// A única observação é se a potência for impar, nesse caso é necessário 
// dividir por 2 e multiplicar ainda a base de novo (^3);
ll rexp(ll b, ll p, ll mod){
    if(p == 0) return 1;
    if(p == 1) return b;

    ll temp = rexp(b, p>>1, mod);
    temp = (temp * temp) % mod;

    if(p & 1) temp = (temp * b) % mod;
    return temp;
}


int main()
{
    ll b, p, m;

    while(cin >> b >> p >> m)
        cout << rexp(b, p, m) << endl;

    return 0;
}