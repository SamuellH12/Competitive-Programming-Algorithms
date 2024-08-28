#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

/******************** 
// FOR DOUBLE POINT // 
See Geometry - General
*********************/

struct PT {
	ll x, y;
	PT(ll x=0, ll y=0) : x(x), y(y) {}

	PT operator- (const PT&a) const{ return PT(x-a.x, y-a.y); }
	ll operator% (const PT&a) const{ return  (x*a.y - y*a.x); }	//Cross // Vector product

	bool operator==(const PT&a) const{ return x == a.x && y == a.y; }
	bool operator< (const PT&a) const{ return x != a.x ? x < a.x : y < a.y; }
};

// Colinear? Mude >= 0 para > 0 nos while
vector<PT> ConvexHull(vector<PT> pts, bool sorted=false) {
	if(!sorted) sort(begin(pts), end(pts));
	pts.resize(unique(begin(pts), end(pts)) - begin(pts));
	if(pts.size() <= 1) return pts;

	int s=0, n=pts.size();
	vector<PT> h (2*n+1);

	for(int i=0; i<n; h[s++] = pts[i++])
		while(s > 1 && (pts[i] - h[s-2]) % (h[s-1] - h[s-2]) >= 0 )
			s--;

	for(int i=n-2, t=s; ~i; h[s++] = pts[i--])
		while(s > t && (pts[i] - h[s-2]) % (h[s-1] - h[s-2]) >= 0 )
			s--;

	h.resize(s-1);
	return h;
}