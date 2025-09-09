#include <bits/stdc++.h>
using namespace std;

vector<int> calc_prime(int n){ // O(n log n)
    vector<int> prime(n+1, 1);
    for(int i=2; i<=n; i++) if(prime[i] == i)
        for(int j=i+i; j<=n; j+=i)
            prime[j] = false;
	return prime;
}

vector<int> calc_phi(int n){ // O(n log n)
    vector<int> phi(n+1);
    for(int i=0; i<=n; i++) phi[i] = i;
    for(int i=2; i<=n; i++) if(phi[i] == i)
        for(int j=i; j<=n; j+=i)
            phi[j] -= phi[j] / i;
	return phi;
}

vector<int> calc_mobius(int n){ // O(n log n)
    vector<int> mobius(n+1, 1), prime(n+1, 1);
    for(int i=2, j; i<=n; i++) if(prime[i])
        for(mobius[i]=-1, j=i+i; j<=n; j+=i){
            if((j/i)%i) mobius[j] *= -1;
            else mobius[j] = 0;
            prime[j] = false;
        }
    return mobius;
}
