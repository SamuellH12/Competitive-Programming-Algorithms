//Samuell H C P C - OBI 2022 - IFPI
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
	vi p (5);

	for(int i=0, x; i<5; i++)
	{
		cin >> x;
		p[i] = x;
	}
	
	sort(ALL(p));

	int t=0, pl=0;
	int top = p[4];
	bool prim = true;

	for(int i=4; i>=0; i--)
	{
		if(prim && p[i] == top) t++;
		else if(prim)
		{
			top = p[i];
			pl++;
			prim = false;
		}
		else if(!prim && p[i] == top) pl++;
		else if(!prim && p[i] != top) break;
	}

	cout << t << " " << pl << endl;
	
	return 0;	
}
