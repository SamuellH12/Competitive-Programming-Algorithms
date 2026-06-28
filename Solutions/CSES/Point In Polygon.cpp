#include <bits/stdc++.h>
#define ll long long
#define ld double
using namespace std;
// https://cses.fi/problemset/task/2192

vector<string> ans = {
    "OUTSIDE",
    "INSIDE",
    "BOUNDARY"
};


struct PT {
	ll x, y;
	PT(ll x, ll y) : x(x), y(y) {}
	PT() : x(0), y(0){}

	PT operator+(const PT&a)const{return PT(x+a.x, y+a.y);}
	PT operator-(const PT&a)const{return PT(x-a.x, y-a.y);}
	ll operator*(const PT&a)const{return  (x*a.x + y*a.y);} //DOT
	ll operator%(const PT&a)const{return  (x*a.y - y*a.x);} //Cross
	bool operator==(const PT&a) const{ return x == a.x && y == a.y; }
	bool operator< (const PT&a) const{ return tie(x, y) < tie(a.x, a.y); }

	ll cross(const PT&a, const PT&b) const{ return (a-*this) % (b-*this); } // (a-p) % (b-p)
};


bool onSegment(PT s, PT e, PT p){ 
	return p.cross(s, e) == 0 && (s-p) * (e-p) <= 0;
}

int ptInsidePol(vector<PT>& pol, PT p){
	int qt = 0;
	for(int i=0, n=pol.size(); i<n; i++){
		auto s = pol[i], e=pol[(i+1)%n];
        
    if(onSegment(s, e, p)) return 2;        
		if((s.y < p.y) == (e.y < p.y)) continue;
        
		qt ^= (s.y < p.y) == (s.cross(p, e) > 0);
	}
	return qt != 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<PT> pol(n);
    for(auto &[x, y] : pol) cin >> x >> y;

    PT p;
    while(m--){
        cin >> p.x >> p.y;

        cout << ans[ptInsidePol(pol, p)] << "\n";
    }
}