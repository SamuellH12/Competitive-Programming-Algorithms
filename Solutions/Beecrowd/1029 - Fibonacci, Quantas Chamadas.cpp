#include <bits/stdc++.h>
using namespace std;

int nCalls = -1;
int dp[50];
bool dpb[50];

int fib(int N){

    nCalls++;

    if( N == 0) return 0;
    if( N == 1) return 1;

    return dp[N] = fib(N - 1) + fib(N - 2); 
}

 
int main() {
    
    int casos; cin>>casos;

    for(int i=0; i<casos; i++){

        int n; cin>>n;

        int resp = fib(n);

        cout<<"fib("<<n<<") = "<<nCalls<<" calls = "<<resp<<endl;
        
        nCalls = -1;

    }


    return (0);
}