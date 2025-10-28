#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ld func(ld x){ return 2*x*x - 4*x + 2; }

ld ternary_search(ld l, ld r) {
    for(int it=250; it--;){
        ld m1 = l + (r-l)/3, m2 = r - (r-l)/3;
        ld f1 = func(m1), f2 = func(m2);
        if(f1 < f2) r = m2;
        else l = m1;
    }
    return l;
}

ld golden_search(ld l, ld r) {
    const ld iphi = (sqrt(5)-1)/2;

    ld m1 = r - iphi*(r-l);
    ld m2 = l + iphi*(r-l);
    ld f1 = func(m1), f2 = func(m2);

    for(int it=250; it--;){
        if(f1 < f2){
            r = m2; 
            tie(m2, f2) = tie(m1, f1);
            f1 = func( m1 = r - iphi*(r-l) );
        } else {
            l = m1; 
            tie(m1, f1) = tie(m2, f2);
            f2 = func( m2 = l + iphi*(r-l) );
        }
    }
    return l;
}

int iternary_search(int l, int r) {
    while(r-l > 5){  //margem de segurança
        int m1 = l + (r-l)/3, m2 = r - (r-l)/3;
        int f1 = func(m1), f2 = func(m2);
        if(f1 < f2) r = m2;                           
        else l = m1;
    }
    int ans = r, fa = func(ans);
    for(int f1; l<r; l++){
        f1 = func(l);
        if(f1 < fa) 
            ans = l, fa = f1;
    }
    return ans;
}

/*LATEX_DESC_BEGIN***************************
**Ternary search and Golden section search**

**if(f1 < f2) to find minimum**
**if(f1 > f2) to find maximum**

Golden Search faz menos chamadas a funcao;
Para busca em inteiros, cuidado, mantenha uma margem do L e R para evitar looping infinito.
*****************************LATEX_DESC_END*/