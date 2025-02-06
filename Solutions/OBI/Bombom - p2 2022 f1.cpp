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

	string dom; cin>>dom;
	string l[3];
	string e[3];

	for(int i=0; i<3; i++) cin>>l[i];
	for(int i=0; i<3; i++) cin>>e[i];

	int ptl=0, pte=0;

	for(int i=0; i<3; i++)
	{
		if(l[i][1] == dom[1]) ptl += 4;
		if(e[i][1] == dom[1]) pte += 4;
		
		if(l[i][0] == 'A') ptl += 10;
		if(l[i][0] == 'J') ptl += 11;
		if(l[i][0] == 'Q') ptl += 12;
		if(l[i][0] == 'K') ptl += 13;

		if(e[i][0] == 'A') pte += 10;
		if(e[i][0] == 'J') pte += 11;
		if(e[i][0] == 'Q') pte += 12;
		if(e[i][0] == 'K') pte += 13;
	}

	if(pte == ptl) cout << "empate" << endl;
	else cout << (ptl > pte ? "Luana" : "Edu") << endl;
	
	//cout << ptl << pte;

	return 0;	
}
