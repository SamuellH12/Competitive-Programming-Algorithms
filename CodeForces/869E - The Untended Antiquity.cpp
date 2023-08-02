#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
using namespace std;
//https://codeforces.com/problemset/problem/869/E
#define ll long long

const int MAXN = 2500 + 5;

struct BIT2D {
	ll bit[MAXN][MAXN];

	void update(int X, int Y, int val)
	{
		for(int x = X; x < MAXN; x += x&(-x))
			for(int y = Y; y < MAXN; y += y&(-y))
				bit[x][y] += val;
	}

	void updateArea(int xi, int yi, int xf, int yf, int val){
		update(xi, yi, val); 
		update(xf+1, yi, -val); 
		update(xi, yf+1, -val);
		update(xf+1, yf+1, val);
	}

	ll query(int X, int Y)
	{
		int sum = 0;

		for(int x = X; x > 0; x -= x&(-x))
			for(int y = Y; y > 0; y -= y&(-y))
				sum += bit[x][y];
			
		return sum;
	}

	ll queryArea(int xi, int yi, int xf, int yf){
		return query(xf, yf) - query(xf, yi-1) - query(xi-1, yf) + query(xi-1, yi-1);
	}

	void init(){
		memset(bit, 0, sizeof bit);
	}

} bit;

#include <ext/random>
__gnu_cxx::sfmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b){return uniform_int_distribution<ll>(a, b)(rng);}

int32_t main(){
	optimize;
	bit.init();
	//mt19937 rnd( chrono::steady_clock::now().time_since_epoch().count()  );

	int n, m;
	cin >> n >> m;

	int q;
	cin >> q;

	int tp, x1, y1, x2, y2;
	while(q--){
		cin >> tp >> x1 >> y1 >> x2 >> y2;

		if(tp == 1)
		{
			ll temp = rng();
			bit.updateArea(x1, y1, x2, y2, temp);

		}
		else
		if(tp == 2)
		{
			ll val = bit.queryArea(x1, y1, x1, y1);
			bit.updateArea(x1, y1, x2, y2, -val);
		}
		else
		{
			ll q1 = bit.query(x1, y1);
			ll q2 = bit.query(x2, y2);

			cout << (q1 == q2 ? "Yes" : "No" ) << endl;
		}
	}
	
	
	return 0;	
}
