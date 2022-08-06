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
	int n; cin >> n;
	vi caixas;

	while(n--)
	{
		int temp;
		cin >> temp;
		caixas.push_back(temp);
	}

	sort(ALL(caixas));

	bool possivel = true;
	int ant = 0;
	for(int x : caixas){
		if( x - ant > 8)
		{	
			possivel = false;
			break;
		}
		ant = x;
	}
	
	cout << (possivel ? "S" : "N") << endl;

	return 0;	
}
