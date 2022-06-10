#include <bits/stdc++.h>
#define endl "\n"
#define ll unsigned long long int
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;

int main(){

	string rs, gs, bs;
	cin >> rs >> gs >> bs;

	ll r = stoi(rs, 0, 16);
	ll g = stoi(gs, 0, 16);
	ll b = stoi(bs, 0, 16);

	ll resp = 0;

	resp += (r/g)*(r/g);
	resp += ((g/b)*(g/b)) * resp;
	resp++;

	string ans = "";
	char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	while(resp > 0)
	{
		ans = hex[ resp%16 ] + ans; 
		resp /= 16;
	}

	cout << ans << endl;

	return 0;	
}
