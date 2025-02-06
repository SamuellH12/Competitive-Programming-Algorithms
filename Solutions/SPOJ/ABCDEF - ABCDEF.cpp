#include <bits/stdc++.h>
using namespace std;

//https://www.spoj.com/problems/ABCDEF/en/

int main(){

	int n, resp=0;
	cin >> n;

	int a[n];

	for(int i=0; i<n; i++)
		cin >> a[i];

	map<int, int> mp;

	//test for l
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				mp[ a[i]*a[j]+a[k] ]++;


	//test for r
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				if( a[k] != 0 && mp.find((a[i]+a[j])*a[k]) != mp.end() )
					resp += mp[ (a[i]+a[j])*a[k] ];
			

	cout << resp << endl;

	return 0;
}



/* O(n^3)

(a*b+c)/d - e = f
->
(a*b+c)/d = f + e
->
a*b+c = (f + e)*d
left    -  rigth

CUIDADO: D tem sempre de ser != 0, pq 
na equação inicial ele está dividindo e
nunca se pode dividir por 0

*/