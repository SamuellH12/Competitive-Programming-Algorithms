#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;



int main(){
	int p, q;
	cin>>p>>q;

	int valor = p / q + 1;
	int qtd = p % q;

	for(int i=0; i<q; i++)
		cout<<(i < qtd ? valor : valor - 1)<<endl;
	

	return 0;	
}
