#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 1000010
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;
//https://codeforces.com/gym/102021

vi fib (1, 1);

void calcFib(int limite)
{
	while(true)
	{
		int sz = fib.size();
		fib.push_back( fib[sz - 2] + fib[sz - 1] );
		if(fib[sz] > limite) break;
	}
}


int eFib(int x)
{
	int l = 0, r = fib.size(), mid;

	while(l <= r)
	{
		mid = (l+r)/2;

		if(fib[mid] > x)
			r = mid - 1;
		else
		if(fib[mid] < x)
			l = mid + 1;
		else
			return mid;
	}

	return -1;
}

int main(){
	int n; cin>>n;
	vector<pii> monstro (n+1);
	int MAX = 0;

	for(int i=1, p; i<=n; i++)
	{
		cin>>p;
		monstro[i] = {p, i};
		MAX = max(MAX, p);
	}

	fib.push_back(2);
	calcFib(MAX);
	sort(ALL(monstro));

	if(monstro[1].first == 1 && monstro[2].first == 1)
	{
		cout<<monstro[1].second<<" "<<monstro[2].second<<endl;
		return 0;
	}


	for(int i=1; i<n; i++)
	{
		int iFib = eFib(monstro[i].first);
		
		if(  iFib == -1 ) continue;

		int proxFib = fib[iFib + 1];
		
		int l = i+1, r = n, mid, resp = 0;
		while(l <= r)
		{
			mid = (l+r)/2;
			
			if(monstro[mid].first > proxFib)
			{
				r = mid - 1;
			}
			else
			if(monstro[mid].first < proxFib)
			{
				l = mid + 1;
			}
			else
			{
				resp = monstro[mid].second;
				break;
			}
		}


		if(resp != 0)
		{
			cout<<monstro[i].second<<" "<<resp<<endl;
			return 0;
		}

	}

	cout<<"impossible"<<endl;

	return 0;	
}

//https://vjudge.net/contest/479100#problem/F