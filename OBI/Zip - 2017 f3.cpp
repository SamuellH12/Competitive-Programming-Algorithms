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
	int l1, l2, c1, c2, pontl, pontc;
	cin>>l1>>l2>>c1>>c2;

	if(l1 == l2)           pontl = l1 * 4;   else
	if(abs(l1 - l2) == 1)  pontl = (l1 + l2) * 3;
	else 				   pontl = l1 + l2;

	if(c1 == c2)           pontc = c1 * 4;   else
	if(abs(c1 - c2) == 1)  pontc = (c1 + c2) * 3;
	else 				   pontc = c1 + c2;

	if(pontc == pontl) cout<<"empate"<<endl;
	else cout<<( pontl > pontc ? "Lia" : "Carolina" )<<endl;

	return 0;	
}
