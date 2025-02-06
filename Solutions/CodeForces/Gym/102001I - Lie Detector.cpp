#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://codeforces.com/gym/102001/problem/I

int main(){

	int lies; 
	string lot;

	cin>>lies;
	cin>>lot; 

	bool resp = (lot == "LIE" ? false : true);

	lies--;

	while(lies--)
	{
		cin>>lot;
		
		if(lot == "LIE")
		{
			if(resp) resp = false;
			else resp = true;
		}
		else
		{
			if(resp) resp = true;
			else resp = false;
		}
	}

	cout<<(resp ? "TRUTH" : "LIE")<<endl;


	return 0;	
}
