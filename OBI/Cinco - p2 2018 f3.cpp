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
//https://olimpiada.ic.unicamp.br/pratique/p2/2018/f3/cinco/


int main(){
	int n; cin >> n;
	int lista [n];

	//look for 0's
	int pos = -1;
	for(int i=0; i<n; i++)
	{
		cin >> lista[i];

		if(lista[i] == 0 && pos == -1) pos = i;
	}
	
	//se o último número for maior que 5, então compensa mais eu pegar o primeiro 5 ou o primeiro 0 (o que vier primeiro)
	//caso não, pego o último 5 mesmo (contando que não há 0's)

	if( lista[n-1] < 5 && pos == -1 ){
		for(int i=n-2; i>=0 && pos == -1; i--)
			if(lista[i] == 5)  
				pos = i;
	}
	else if( lista[n-1] >= 5 )
		for(int i=0; i<n; i++)
			if(lista[i] == 5 || lista[i] == 0){
				pos = i;
				break;
			}


	if(pos == -1 ){
		cout << pos << endl;
		return 0;
	}

	swap(lista[pos], lista[n-1]);

	for(int i=0; i < n; i++)
		cout << lista[i] << " ";
	cout << endl;
	

	return 0;	
}
