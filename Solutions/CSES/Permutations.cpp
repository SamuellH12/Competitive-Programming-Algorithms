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
	
	if(n>1 && n<4){ cout << "NO SOLUTION" << endl; return 0; }
	if(n == 4){ cout << "3 1 4 2" << endl;  return 0;}

	for(int i=1; i<=n; i+=2) cout << i << " ";
	for(int i=2; i<=n; i+=2) cout << i << " ";
	cout << endl;

	return 0;	
}
