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

// https://codeforces.com/gym/104767/problem/C


int main(){

	int n, m, c;
	cin >> n >> m >> c;

	int a=0, b=0;

	vi sla(m, 0);

	for(int i=0, x, y; i<n; i++)
	{
		cin >> x >> y;
		x--, y--;

		if(sla[x] < c) sla[x]++, a++;
		else
		if(sla[y] < c) sla[y]++, b++;
	}
	
	cout << a << " " << b << endl;
	
	return 0;	
}
