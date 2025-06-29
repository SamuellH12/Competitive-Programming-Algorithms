#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 20;
ll dp[1<<N], iVal[1<<N];

void sosDP(){ // O(N * 2^N) 
    for(int i=0; i<(1<<N); i++) 
        dp[i] = iVal[i];

	for(int i=0; i<N; i++)
		for(int mask=0; mask<(1<<N); mask++)
			if(mask&(1<<i))
				dp[mask] += dp[mask^(1<<i)];
}

void sosDPsub(){ // O(3^N) //suboptimal 
	for (int mask = 0, i; mask < (1<<N); mask++)
		for(i = mask, dp[mask] = iVal[0]; i>0; i=(i-1) & mask) //iterate over all submasks
			dp[mask] += iVal[i];
}
 
/*LATEX_DESC_BEGIN***************************
SOS DP - Sum over Subsets

Dado que cada mask possui um valor inicial (iVal), computa 
para cada mask a soma dos valores de todas as suas submasks.

N -> Número Máximo de Bits
iVal[mask] -> initial Value / Valor Inicial da Mask
dp[mask]   -> Soma de todos os SubSets

Iterar por todas as submasks: for(int sub=mask; sub>0; sub=(sub-1)&mask)
*****************************LATEX_DESC_END*/