#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll k, n, w;
	cin >> k >> n >> w;

	ll cost = 0, uni=0;
	for(int i=0; i<w; i++)
		cost += (uni+=k);

	cout << max(0ll, cost - n) << endl;
		
	return 0;	
}