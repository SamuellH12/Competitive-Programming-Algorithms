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

	int a, b, c;
	cin>>a>>b>>c;

	cout << a+b+c - min({a, b, c}) - max({a, b, c}) << endl;

	return 0;	
}
