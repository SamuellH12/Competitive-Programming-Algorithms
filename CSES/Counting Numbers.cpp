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

// https://cses.fi/problemset/task/2220

vi num;
void fillNum(ll a){
	num.clear();

	if(a == 0) num.push_back(0);

	while(a > 0){
		num.push_back(a%10);
		a /= 10;
	}
}
   //digit|last|limite?
ll memo[20][12][2];

ll solve(int idx, int last, bool lim)
{
	if(idx == -1) return 1;
	ll &ans = memo[idx][last][lim];
	if(ans != -1) return ans;

	ans = 0;

	int newlim = lim ? num[idx] : 9;
	//cerr << "lim = " << newlim << "; ";

	for(int dig=0; dig <= newlim; dig++)
		if(dig != last)
			ans += solve(idx-1, (dig==0 && last==10 ? 10 : dig), (lim && dig == newlim));
	
	return ans;
}

bool rep(ll a){
	int last = 10;

	while(a > 0){
		if( last == a%10) return 0;
		last = a%10;
		a /= 10;
	}

	return 1;
}

ll lazy(ll a, ll b){
	ll resp = 0;
	for(; a <= b; a++)
		if(rep(a)){
			resp++;
			//cerr << a << " / ";
		}
	//cerr << endl;
	return resp;
}

int main(){
	ll a, b;

	cin >> a >> b;
	
	memset(memo, -1, sizeof memo);
	fillNum(b);
	ll B = solve(num.size()-1, 10, true);
	//cerr << "b size = " << num.size() << "; num[0] = " << num[0] << ";\n";

	memset(memo, -1, sizeof memo);
	fillNum(a-1);
	ll A = a > 0 ? solve(num.size()-1, 10, true) : 0;


	//cerr << B << " - " << A << endl;
	//cerr << lazy(a, b) << endl;
	cout << B - A << endl;
		
	return 0;	
}
