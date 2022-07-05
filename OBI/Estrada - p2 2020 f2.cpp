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

	
	int tam, n;

	cin>>tam>>n;

	vector<float> cidades; vector<float> viz;
	cidades.resize(n);
	viz.resize(n);
	//cidades[n+1] = INF;


	for(int i=0; i<n; i++){
		cin>>cidades[i];
		viz[i]=0;
	}

	sort(ALL(cidades));

	float menorviz = INF;

	for(int i=0; i<n; i++){
		if(i==0){
			viz[i] += cidades[i];
		} else{
			viz[i] += (cidades[i] - cidades[i-1])/2;
		}

		if(i==n - 1){
			viz[i] += tam - cidades[i];
		} else{
			viz[i] += (cidades[i+1] - cidades[i])/2;
		}

		menorviz = min(menorviz, viz[i]);

	}


	cout<<fixed<<setprecision(2);

	cout<<menorviz<<endl;


	return 0;	
}
