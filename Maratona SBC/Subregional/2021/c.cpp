#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;

// C. Creating Multiples
// https://codeforces.com/gym/103388/problem/C

int main(){

	ll l, b;
	cin >> b >> l;
	
	ll el = b+1;

	vi dig(l);

	for(auto &x : dig) cin >> x;

	ll sump=0, sumi = 0;

	for(int i=0; i<l; i+=2) sump += dig[i];
	for(int i=1; i<l; i+=2) sumi += dig[i];

	if( abs(sump - sumi) % el == 0 )
	{
		cout << 0 << " " << 0 << endl;
		return 0;
	}


	int j = -1, v = -1;

	for(int i=0; i<l; i++)
	{
		if((i&1) && abs((sump%el) - sumi) % el <= dig[i] )
		{
			j = i+1, v = dig[i] - (abs((sump%el) - sumi) % el);
			break;
		}

		if(!(i&1) && abs(sump - (sumi)%el) % el <= dig[i] )
		{
			j = i+1, v = dig[i] - (abs(sump - (sumi)%el) % el);
			break;
		}


	}

	cout << j << " " << v << endl;
	
	return 0;	
}
