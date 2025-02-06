#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 200000010000
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://codeforces.com/problemset/problem/1201/C

int main(){

    #define int long long //Gambiarra /(.-.)\.
	optimize;

	int n, k, meio;
	cin>>n>>k;
	meio = n/2 + 1;
	vi listag;
	listag.resize(n);
	
	for(int i=0; i<n; i++){
		int aux;
		cin>>aux;
		listag[i] = aux;

	}

	sort(ALL(listag));
	vi lista;

	for(int i=n/2; i<n; i++){
		lista.push_back(listag[i]);
	}




	int esq = 0, dir = INF, med = (esq + dir) / 2, ans;



	while (esq <= dir){
		med = (esq + dir) / 2;

		int soma = 0;

		for(int i=0; i<meio; i++){
			if(lista[i] < med )
				soma += med - lista[i];
		}
		
		if(soma <= k){
			esq = med + 1;
			ans = med;
		} else {
			dir = med - 1;
		}

	
	}
	
	cout<<ans<<endl;

	return 0;
		
}