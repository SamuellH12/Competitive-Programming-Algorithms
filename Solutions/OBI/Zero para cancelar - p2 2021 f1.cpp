//Samuell H C P C - IFPI SRN - OBI2021
#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define sc second
#define ft first
#define debug cout<<"ate aqui ok\n"
using namespace std;

//ZERO

int main(){

	ll int n; cin>>n;

	stack <ll int> pilha;

	for(ll int i=0; i<n; i++)
	{
		ll int x; cin>>x;
		
		if(x != 0)
			pilha.push(x);
		else
			pilha.pop();

	}

	ll int resp = 0;

	for(ll int i=0; i<=100000; i++){

		if(pilha.empty()) break;

		ll int b = pilha.top();
		pilha.pop();
		resp += b;
	}

	if(resp < 0) resp = 0;

	cout<<resp<<endl;

	return 0;	
}
