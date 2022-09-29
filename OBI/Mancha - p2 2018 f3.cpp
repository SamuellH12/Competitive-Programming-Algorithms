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
//https://olimpiada.ic.unicamp.br/pratique/p2/2018/f3/mancha/


int main(){
	int n; cin >> n;

	bool matriz[n][n];

	char x; 
	bool ini, fim;

	for(int i=0; i<n; i++){
		fim = ini = false;
		for(int j=0; j<n; j++){
			cin >> x;
			matriz[i][j] = (x == '.' ? false : true);
			
			if(matriz[i][j] && !ini){
				ini = true;
			}
			else if(!matriz[i][j] && ini){
				fim = true;
			} 
			else if(matriz[i][j] && fim){	//achou um gap
				cout << "N" << endl;
				return 0;
			}
		}
	}


	for(int j=0; j<n; j++){
		fim = ini = false;
		for(int i=0; i<n; i++){
			
			if(matriz[i][j] && !ini){
				ini = true;
			}
			else if(!matriz[i][j] && ini){
				fim = true;
			} 
			else if(matriz[i][j] && fim){	//achou um gap
				cout << "N" << endl;
				return 0;
			}
		}
	}
	

	cout << "S" << endl;
	
	return 0;	
}


/*
Simples, se houver um gap, vertical ou horizontal, é N
se não, se for contínuo, S.

*/