#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;


int main(){
	int n, d;
	cin >> n >> d;

	vector<ll> sanduba; sanduba.push_back(0);
	vector<ll> sum (n*2 + 1); sum[0] = 0;

	for(int i=1, p; i<=n; i++)
	{
		cin >> p;
		sanduba.push_back(p);
		sum[i] = sum[i-1] + p;
	}

	for(int i=n+1; i<=2*n; i++)
		sum[i] = sum[i-1] + sanduba[i - n];
	

	if(sum[n] < d)
	{
		cout << 0 << endl;	//CUIDADO!!! Se o sanduiche < d é impossível
		return 0;			//sem essa verificação, {5 6 1 1 1 1 1} daria que é possível
	}

	long long resp = 0;

	for(int i=1; i<=n; i++)
	{
		resp += upper_bound(sum.begin()+i, sum.end(), sum[i-1] + d) 
			  - lower_bound(sum.begin()+i, sum.end(), sum[i-1] + d);
	}
	
	cout << resp << endl;
	
	return 0;	
}
