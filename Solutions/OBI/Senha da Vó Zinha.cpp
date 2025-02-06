#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;


int main(){
	int n, b, k, p;
	string senha;
	cin >> n >> b >> k;
	cin >> senha;

	string letras[b];
	for(int i=0; i<b; i++){
		cin >> letras[i];
		sort(ALL(letras[i]));
	}

	cin >> p; p--;
	string resp  = "";
	
	ll rep = 1, prim = 0;
	for(int i=0; i < b && rep < p; i++){
		rep *= k;
		prim = b - i - 1; //como as permutações podem chegar a 26^500, calculo só as permutações dos últimos e pego os primeiros
	}

	prim--;

	for(int i=0; i<b; i++)
	{
		if(i < prim ){ resp += letras[i][0]; continue;}

		resp += letras[i][ p/rep ];

		p %= rep;
		rep /= k;
	}

	for(int i=0, j=0; i<senha.size(); i++)
	{
		if(senha[i] != '#') cout << senha[i];
		else{ cout << resp[j]; j++; }
	}
	cout << endl;
	
	return 0;	
}
