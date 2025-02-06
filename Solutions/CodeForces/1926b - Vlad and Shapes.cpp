#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
//https://codeforces.com/contest/1926/problem/B


int main(){
	optimize;
	int t; cin >> t;
	while(t--){

		int n; cin >> n;
		vector<vector<char>> grid(n, vector<char>(n));

		for(auto &v : grid)
			for(auto &x : v) 
				cin >> x;

		bool quad = true, ent = false;

		for(int i=0; i<n && !ent; i++)
			for(int j=0; j<n; j++)
				if(grid[i][j] == '1')
				{

					int sz = 0;

					while(j+sz<n && grid[i][j+sz] == '1') sz++;

					if(sz < 2) quad = false;
					if(sz+i>n){ quad = false;  }
					// cerr << sz << "sz" << endl;
					while(sz > 0 && quad)
					{
						sz--;
						if(i + sz >= n){
							quad = false;
							break;
						}
						if(grid[i+sz][j] != '1') quad = false;
					}

					ent = true;
					break;
				}

		cout << (quad ? "SQUARE" : "TRIANGLE") << endl;
	}
	
	return 0;	
}
