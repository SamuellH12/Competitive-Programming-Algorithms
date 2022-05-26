#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;

//https://www.beecrowd.com.br/judge/pt/problems/view/1912

int main(){
	optimize;
	int n, a;
	cout<<fixed<<setprecision(4);

	while(cin>>n>>a && (n+a))
	{
		int fitas[n], soma = 0;

		for(int i=0; i<n; i++){
			cin>>fitas[i];
			soma += fitas[i];
		}
		
		if(soma == a)
		{
			cout<<":D"<<endl;
			continue;
		}
		else if(soma < a)
		{
			cout<<"-.-"<<endl;
			continue;
		}

		bool print = false;
		float esq = 0, dir = 10000,  meio;
		while (dir - esq > 0.000005)
		{
			meio = (esq+dir)/2;

			float area = 0;
			for(int i=0; i<n; i++)
				area += (fitas[i] > meio ? fitas[i]-meio : 0);
			
			if(area == a)
			{
				cout<<meio<<endl;
				print = true;
				break;
			}
			else if(area < a) dir = meio;
			else esq = meio;
		
		}

		if(!print)
			cout<<meio<<endl;
	}
	
	return 0;	
}
