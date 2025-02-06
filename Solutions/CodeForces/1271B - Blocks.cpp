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
//https://codeforces.com/problemset/problem/1271/B

string s;

vi f(char x)
{
	string st = s;
	vi resp;
	bool trocou = false;

	for(int i=0; i < st.size() - 1; i++)
	{
		if(st[i] == x)
			continue;
		else
		{
			resp.push_back(i+1);
			st[i+1] = (st[i+1] == 'W' ? 'B' : 'W');
			trocou = true;
		}
	}

	if(st.back() != x)
	{
		return vi (1, -1);
	}

	if(!trocou) return vi (1, 0);

	return resp;
}

int main(){

	int t; cin>>t;
	cin>>s;

	auto w = f('W');
	auto b = f('B');

	if(w[0] == -1 && b[0] == -1)
	{
		cout<<-1<<endl;
	}
	else 
	if(w[0] == -1)
	{
		if(b[0] != 0)
		{
			cout<<b.size()<<endl;
			for(auto a : b) cout<<a<<" ";
			cout<<endl;
		}
		else cout<<0<<endl;

	}
	else
	if(b[0] == -1)
	{
		if(w[0] != 0)
		{
			cout<<w.size()<<endl;
			for(auto a : w) cout<<a<<" ";
			cout<<endl;
		}
		else cout<<0<<endl;
		
	}
	else
	if( w.size() < b.size() )
	{
		if(w[0] != 0)
		{
			cout<<w.size()<<endl;
			for(auto a : w) cout<<a<<" ";
			cout<<endl;
		}
		else cout<<0<<endl;
	}
	else
	{
		if(b[0] != 0)
		{
			cout<<b.size()<<endl;
			for(auto a : b) cout<<a<<" ";
			cout<<endl;
		}
		else cout<<0<<endl;
	}

	return 0;	
}
