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


vi prefixos(string& s)
{
	vi pre (s.size(), 0);

	for(int i=1, j=0; i < s.size(); i++)
	{
		while(j>0 && s[j] != s[i]) j = pre[j-1];
		
		if(s[j] == s[i]) j++;

		pre[i] = j;
	}

	return pre;
}


vi kmp(string& s, string& p)
{
	vi pre = prefixos(p);
	vi match;

	for(int i=0, j=0; i<s.size(); i++)
	{
		while(j>0 && p[j] != s[i]) j = pre[j-1];

		if(p[j] == s[i]) j++;

		if( j == p.size() )	match.push_back(i-j+1),	j = pre[j-1];
	}

	return match;
}


int main(){
	optimize;
	int n; cin>>n;

	while(n--)
	{
		string a, p;
		cin>>a>>p;

		vi indice = kmp(a, p);

		if(indice.size() > 0)
		{
			cout<<indice.size()<<endl;
			for(auto i : indice) cout<<i+1<<" ";
			cout<<endl;
		}
		else
		{
			cout<<"Not Found"<<endl;
		}
		

		if(n > 0) cout<<endl;
	}


	return 0;	
}

//https://www.spoj.com/problems/NAJPF/