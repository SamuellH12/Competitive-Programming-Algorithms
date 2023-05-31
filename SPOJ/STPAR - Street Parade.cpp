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

//https://www.spoj.com/problems/STPAR/

int main(){

	int n;

	while(cin >> n && n){

		vi lista (n);

		for(auto &x : lista) cin >> x;

		stack<int> s;
		int i=1, j=0;

		while( i<=n && j <= n )
		{
			if(lista[j] == i){
				j++;
				i++;
			}
			else
			if(!s.empty() && s.top() == i){
				s.pop();
				i++;
			}
			else
			{
				s.push(lista[j]);
				j++;
			}
		}

		if(s.size() > 0 || i < n || j < n)
			cout << "no" << endl;
		else
			cout << "yes" << endl;

	}
	
	return 0;	
}
