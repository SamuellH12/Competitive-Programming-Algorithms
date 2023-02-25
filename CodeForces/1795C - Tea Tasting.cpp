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

#define int long long

int32_t main(){
	optimize;

	int t; cin >> t;

	while(t--)
	{
		int n; cin >> n;

		int tea[n], tast[n], drink[n];
		memset(drink, 0, sizeof drink);

		for(int i=0; i<n; i++) cin >> tea[i];
		for(int i=0; i<n; i++) cin >> tast[i]; 
		

		int sum = 0;
		multiset<int> q;

		for(int i=0; i<n; i++)
		{
			q.insert(sum + tea[i]);

			while( !q.empty() && *q.begin() - sum <= tast[i] )
			{
				drink[i] += *q.begin() - sum;
				q.erase(q.begin()); 								//erase geralmente é O(log), mas como já estou passando o ponteiro e é no begin, o custo é O(1)
			}

			drink[i] += q.size() * tast[i]; 
			sum += tast[i];
		}

		for(int i=0; i<n; i++) cout << drink[i] << " ";
		cout << endl;
	}
	
	
	return 0;	
}
