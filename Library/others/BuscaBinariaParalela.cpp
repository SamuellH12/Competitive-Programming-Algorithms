#include <bits/stdc++.h>
#define ll long long
using namespace std;

void reset(){};
void update(int mid){};
bool check(int i){}

//q = #queries | [0, k-1] = intervalo de busca
vector<int> pbs(int q, int k){ 
    bool LACK = true; 
    vector<int> L(q, 0), R(q, k-1), ans(q, -1);
    vector<vector<int>> atMid(k);
    
    while(LACK){
        reset(); LACK = false;

        for(int i=0; i<q; i++)
            if(L[i] <= R[i])
                atMid[(L[i]+R[i])/2].push_back(i), LACK = true;
        
        for(int mid=0; mid<k; mid++){
            update(mid);
            for(auto i : atMid[mid])
                if(check(i)) R[i] = mid-1, ans[i] = mid;
                else L[i] = mid+1;
            atMid[mid].clear();
        }
    }
    return ans;
}

vector<int> ans; // recursive version
void pbsR(vector<int> &qidx, int l, int r){
	if(l > r) return;
	int mid = (l+r)/2; update(mid);
	vector<int> L, R;
	for(auto i : qidx){
		if(check(i)) L.push_back(i), ans[i] = mid;
		else R.push_back(i);
	}
	if(!L.empty()) pbsR(L, l, mid-1);
	if(!R.empty()) pbsR(R, mid+1, r);
}

/*LATEX_DESC_BEGIN***************************
**Busca Binária Paralela** - O(Q+K log K)

Dado **K** updates ordenados pelo tempo, e **Q** queries da forma:
- Qual o primeiro momento entre [0, K-1] em que * é verdade?
De forma que:
- A resposta é monotônica (se é verdadeiro para t=x, é verdade para t'=x+1)
- É possível responder em O(N^2) iterando pelos updates e verificando a cada passo todas as queries não satisfeitas ainda.

* No caso do range de busca ser [0, 1e9]: recursivo OU veja se é possível olhar apenas os valores que aparecem no input(?)
*****************************LATEX_DESC_END*/