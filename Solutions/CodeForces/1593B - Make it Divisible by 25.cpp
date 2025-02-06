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

int n;

int div(string num)
{
	int resp = 0;
	bool zero = false;

	for(int i=num.size()-1; i>=0; i--)
	{
		if(!zero && num[i] == '0')
		{
			zero = true;
		}
		else
		if(zero && (num[i] == '5' || num[i] == '0') )
		{
			break;
		}
		else
		{
			resp++;
		}
	}

	return resp;
}

int div5(string num)
{
	int resp = 0;
	bool cinco = false;

	for(int i=num.size()-1; i>=0; i--)
	{
		if(!cinco && num[i] == '5')
		{
			cinco = true;
		}
		else
		if(cinco && (num[i] == '7' || num[i] == '2') )
		{
			break;
		}
		else
		{
			resp++;
		}
	}

	return resp;
}

int main(){
	optimize;
	cin>>n;

	while(n--)
	{
		string num, num0;
		cin>>num;
		
		int resp = div(num),
		 resp5 = div5(num);

		cout<<min(resp, resp5)<<endl;
	}

	return 0;	
}


//https://codeforces.com/problemset/problem/1593/B