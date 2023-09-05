#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e5 + 5;
using namespace std;

// E. Dangerous Dive
// https://codeforces.com/gym/101473/attachments


bool p [MAXN];

int main(){

	int n, m;
	cin >> n >> m;

	if(n == m){
		cout << "*\n";
		return 0;
	}


	for(int i=0, x; i<m; i++)
	{
		cin >> x;
		p[x] = 1;
	}

	for(int i=1; i<=n; i++)
	{
		if(!p[i]) cout << i << " ";
	}
	
	cout << endl;
	
	return 0;	
}
