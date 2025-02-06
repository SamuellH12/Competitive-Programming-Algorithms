#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;



int main(){
	int n, resp=0;
	vi p;
	
	cin>>n;

	for(int i=0; i<n; i++)
	{
		int aux; cin>>aux;
		p.push_back(aux);
	}

	sort(ALL(p));

	int inicio=0, fim = n-1;
	
	while(inicio<fim)
	{
		int meio = (inicio+fim)/2 + 1;

		if(p[meio] >= p.size() - meio)
		{
			resp = p.size() - meio;
			fim = meio - 1;
		}
		else 
			inicio = meio;
	}

	cout<<resp<<endl;

	return 0;	
}