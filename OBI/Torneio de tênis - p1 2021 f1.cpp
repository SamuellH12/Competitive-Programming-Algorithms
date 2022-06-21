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

int main(){

	int resp = 0;

	string v = "V";
	
	for(int i=0; i<6; i++){
		string r; cin>>r;
		if(r == v) resp++;
	}

	if(resp >= 5) cout<<1<<endl;
	else if(resp >= 3) cout<<2<<endl;
	else if(resp >= 1) cout<<3<<endl;
	else cout<<-1<<endl;



	return 0;	
}
