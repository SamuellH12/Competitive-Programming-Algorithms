#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define pii pair<int,int>
const int MAXN = 1e6 + 5;
using namespace std;

int bit[MAXN];

void update(int pos, int v){
	for(; pos<MAXN; pos += pos&-pos)
		bit[pos] += v;
}
ll query(int pos){
	int sum = 0;
	for(; pos > 0; pos -= pos&-pos)
		sum += bit[pos];
	return sum;
}

int main(){
	optimize;
	int n; ll p, q;
	cin >> n >> p >> q;

	if(q < 0) p *= -1, q *= -1;	//inverte tudo se Q for negativo

	vector<pii> sla(n);
	map<ll, int> coord;

	for(auto &[x, y] : sla)
	{
		cin >> x >> y;
		coord[q*y - p*x] = -1;
	}

	sort(ALL(sla));	//sorta

	int cnt = 1;	// compressão de coordenadas
	for(auto [k, v] : coord)
		coord[k] = cnt++;


	// calcula a resp
	ll ans = 0;
	for(auto &[x, y] : sla)
	{
		ans += query(coord[q*y - p*x]);
		update(coord[q*y - p*x], 1);
	}
	
	cout << ans << endl;

	return 0;	
}
