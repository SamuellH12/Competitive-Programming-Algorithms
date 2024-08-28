#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

// !!! NOT TESTED !!! //

struct PT {
	ll x, y;
	PT(ll x=0, ll y=0) : x(x), y(y) {}

	PT operator+ (const PT&a) const{ return PT(x+a.x, y+a.y); }
	PT operator- (const PT&a) const{ return PT(x-a.x, y-a.y); }
	ll operator* (const PT&a) const{ return  (x*a.x + y*a.y); }	//DOT product  // norm // lenght^2 // inner
	ll operator% (const PT&a) const{ return  (x*a.y - y*a.x); }	//Cross // Vector product
	PT operator* (ll c) const{ return PT(x*c, y*c); }
	PT operator/ (ll c) const{ return PT(x/c, y/c); }
	
	bool operator==(const PT&a) const{ return x == a.x && y == a.y; }
	bool operator< (const PT&a) const{ return x != a.x ? x < a.x : y < a.y; }
	bool operator<<(const PT&a) const{ PT p=*this; return (p%a == 0) ? (p*p < a*a) : (p%a < 0);  } //angle(p) < angle(a)
};

/******************** 
// FOR DOUBLE POINT // 
const ld EPS = 1e-9;
bool eq(ld a, ld b){ return abs(a-b) < EPS; } // ==
bool lt(ld a, ld b){ return a + EPS < b;    } // <
bool gt(ld a, ld b){ return a > b + EPS;    } // >
bool le(ld a, ld b){ return a < b + EPS;    } // <= 
bool ge(ld a, ld b){ return a + EPS > b;    } // >= 
bool operator==(const PT&a) const{ return eq(x, a.x) && eq(y, a.y); }				// for double point
bool operator< (const PT&a) const{ return eq(x, a.x) ? lt(y, a.y) : lt(x, a.x); }	// for double point
bool operator<<(PT&a){ PT&p=*this; return eq(p%a, 0) ? lt(p*p, a*a) : lt(p%a, 0);  } //angle(this) < angle(a)
//Change LL to LD and uncomment this
//Also, consider replacing comparisons with these functions
*********************/

ld dist  (PT a, PT b){ return sqrtl((a-b)*(a-b)); }	                   // distance from A to B
ld angle (PT a, PT b){ return acos((a*b) / sqrtl(a*a) / sqrtl(b*b)); } //Angle between A and B
PT rotate(PT p, double ang){ return PT(p.x*cos(ang) - p.y*sin(ang), p.x*sin(ang) + p.y*cos(ang)); } //Left rotation. Angle in radian

ll Area(vector<PT>& p){
  ll area = 0;  
  for(int i=2; i < p.size(); i++)
    area += (p[i]-p[0]) % (p[i-1]-p[0]);
  return abs(area) / 2LL;
}

PT intersect(PT a1, PT d1, PT a2, PT d2){
  return a1 + d1 * (((a2 - a1)%d2) / (d1%d2));
}

ld dist_pt_line(PT a, PT l1, PT l2){ 
	return abs( ((a-l1) % (l2-l1)) / dist(l1, l2)  ); 
}

ld dist_pt_segm(PT a, PT s1, PT s2){
  if(s1 == s2) return dist(s1, a);
  
  PT d = s2 - s1;
  ld t = max(0.0L, min(1.0L, ((a-s1)*d) / sqrtl(d*d)) );

  return dist(a, s1+(d*t));
}