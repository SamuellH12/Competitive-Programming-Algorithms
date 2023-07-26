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
//https://codeforces.com/gym/102279/problem/J

int main () {
    string number;
    cin >> number;

	for(int i=number.size() - 2; i >= 0; i--)
	{
		int minMax = -1;
		int minMaxI;
		for(int e=i+1; e<number.size(); e++)
			if( number[i] > number[e] && number[e] > minMax && !(i == 0 && number[e] == '0'))
			{
				minMax = number[e];
				minMaxI = e;
			}
				
		if(minMax != -1)
		{
			swap(number[i], number[minMaxI]);
			cout<<number<<endl;
			return 0;
		}
	}

	cout<<-1<<endl;

    return 0;
}