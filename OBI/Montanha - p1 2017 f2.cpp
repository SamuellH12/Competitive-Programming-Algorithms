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

	int n;
	cin>>n;

	int alt[n + 2];
	alt[0] = 0; alt[n+1]=0;
	
	int qtd = 1;
	bool primeiro = false;

	for(int i=1; i<=n; i++)
		cin>>alt[i];

	

	for(int i=0; i<=n; i++){

		if(alt[i]<alt[i+1]){
			if(primeiro)qtd++;
		} else {
			primeiro = true;
		}

	}

	cout<< (qtd > 1 ? "S" : "N") << endl;



	return 0;	
}
