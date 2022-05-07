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



int main(){

	int n; cin>>n;
	vi choc;

	for(int i=0, c; i<n; i++)
	{
		cin >> c;
		choc.push_back(c);
	}

	sort(ALL(choc));

	int preco = 0;
	int cont = 1;
	for(int i=n-1; i>=0; i--)
	{
		if(cont != 3) preco += choc[i];

		cont++;
		if(cont > 3) cont = 1;
	}

	cout<<preco<<endl;

	return 0;	
}
