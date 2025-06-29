#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll dp[2][19][170];
 
int limite[19];
ll digitDP(int idx, int sum, bool flag){
    if(idx < 0) return sum;
    if(~dp[flag][idx][sum]) return dp[flag][idx][sum];

    dp[flag][idx][sum] = 0; 
	int lm = flag ? limite[idx] : 9;
 
    for(int i=0; i<=lm; i++)
        dp[flag][idx][sum] += digitDP(idx-1, sum+i, (flag && i == lm));
 
    return dp[flag][idx][sum];
}

ll solve(ll k){
    memset(dp, -1, sizeof dp);
	
	int sz=0;
	while(k){
		limite[sz++] = k % 10LL;
		k /= 10LL;
	}

 	return digitDP(sz-1, 0, true);
}

/*LATEX_DESC_BEGIN***************************
Digit DP - Sum of Digits

Solve(K)  ->  Retorna a soma dos dígitos de todo número X tal que: 0 <= X <= K
dp[D][S][f]  ->  D: Quantidade de dígitos; S: Soma dos dígitos; f: Flag que indica o limite.
int limite[D] -> Guarda os dígitos de K.

**Complexity:** O(D^2 * B^2)  (B = Base = 10)
*****************************LATEX_DESC_END*/