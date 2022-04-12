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

	int pos[17], k, l;
	for(int i=1; i<17; i++){
		cin>>pos[i];
		if(pos[i]==1) k = i;
		if(pos[i]==9) l = i;
	}

	if( (k<=8 && l<=8) || (k>8 && l>8) ){
		if( (k<=4 && l<=4) || (k<=8 && k>4 && l<=8 && l>4) || (k>8 && k<=12 && l>8 && l<=12) || (k>12 && l>12) ){
			if( (k+1==l && l%2==0) || (l+1==k && k%2==0)){
					cout<<"oitavas"<<endl;
			}else cout<<"quartas"<<endl;
		} else cout<<"semifinal"<<endl;
	} else cout<<"final"<<endl;
	

	return 0;	
}
