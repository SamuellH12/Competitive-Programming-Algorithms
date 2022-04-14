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
	optimize;
	int n;

	while(cin>>n){
		int maior = 0, l;

		for(int i=0; i<n; i++){

			cin>>l;
			if(maior<20)
			maior=max(l, maior);

		}

		if(maior < 10) 			cout<<1<<endl;
		else if(maior >= 20) 	cout<<3<<endl;
		else 					cout<<2<<endl;

	}

	return 0;	
}
