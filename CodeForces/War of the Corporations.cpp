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

vi pi(string& p)
{
	vi pre (p.size());

	for(int i=1, j=0; i < p.size(); i++)
	{
		while(j>0 && p[i] != p[j]) j = pre[j-1];

		if(p[i] == p[j]) j++;

		pre[i] = j;
	}

	return pre;
}


ll kmp(string& s, string& p)
{
	vi pre = pi(p);
	ll match = 0;

	for(int i=0, j=0; i<s.size(); i++)
	{
		while(j>0 && s[i] != p[j]) j = pre[j-1];

		if(s[i] == p[j]) j++;

		if(j == p.size())
		{
			match++;
			j = 0;// = pre[j-1];
		}
	}

	return match;
}

int main(){
	optimize;
	string a, b;
	cin>>a>>b;
	
	ll rep = kmp(a, b);

	cout<<rep<<endl;

	return 0;	
}

//https://codeforces.com/contest/625/problem/B