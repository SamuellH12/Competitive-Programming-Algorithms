#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 100000100
#define debug cout<<"ate aqui ok\n"
using namespace std;

  //1.000.000.000

int main(){
	optimize;

	unsigned ll n, f, t=0, d=0;
	cin>>n>>f;

	int cap[n];

	for(int i=0; i<n; i++) cin>>cap[i];


	int esq=0, dir=INF;
	while(dir>=esq){
		int t = 0, meio=(esq+dir)/2;

		for(int i=0; i<n; i++)
			t += meio/cap[i];

		if(t>=f){
			d=meio;
			dir=meio-1;
		} else esq=meio+1;
	}

	cout<<d<<endl;

	return 0;	
}

//https://olimpiada.ic.unicamp.br/pratique/p1/2018/f2/capsulas/