#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 20;
ll dp[1<<N], iVal[1<<N];

void sosDP()
{
    for(int i=0; i<(1<<N); i++) 
        dp[i] = iVal[i];

	for(int i=0; i<N; i++)
		for(int mask=0; mask<(1<<N); mask++)
			if(mask&(1<<i))
				dp[mask] += dp[mask^(1<<i)];
}
 
/*********************
SOS DP - Sum over Subsets

Complexity: O(N * 2^N)    
(in CF with N=20 and without I/O -> Used:  77 ms,   8196 KB )
(in CF with N=23 and without I/O -> Used: 483 ms, 131328 KB )

Dado que cada mask possui um valor inicial (iVal),
computa para cada mask a soma dos valores de todas as suas submasks.

N -> Número Máximo de Bits
iVal[mask] -> initial Value / Valor Inicial da Mask
dp[mask]   -> Soma de todos os SubSets
*********************/