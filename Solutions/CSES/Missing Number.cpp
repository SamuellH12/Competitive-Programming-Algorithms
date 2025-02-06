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



int main(){

	int n; cin >> n;

	vi sla(n-1);

	for(auto &x : sla) cin >> x;

	sort(ALL(sla));

	for(int i=1; i<n; i++)
		if(sla[i-1] != i)
		{
			cout << i << endl;
			return 0;
		}

	cout << n << endl;
	
	return 0;	
}
