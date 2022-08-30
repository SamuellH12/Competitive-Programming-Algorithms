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

//TFC - 2020

int main(){

	float m, n;
	cin>>m>>n;

	int valor = (m/10)*3;

	cout<<( valor >= n ? valor : 0)<<endl;
	
	return 0;	
}
