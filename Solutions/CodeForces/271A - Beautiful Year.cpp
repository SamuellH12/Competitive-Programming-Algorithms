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
//https://codeforces.com/problemset/problem/271/A


bool repetidos(int num)
{
	bool usados[11];

	for(int i=0; i<11; i++) usados[i] = false;

	while(num > 0)
	{
		if(usados[num%10]) return true;

		usados[num%10] = true;

		num /= 10;
	}

	return false;

}


int main(){
	int ano; cin >> ano;
	ano++;
	while(repetidos(ano))
	{
		ano++;
	}
	
	cout<<ano<<endl;

	return 0;	
}

//https://vjudge.net/contest/478045#problem/A