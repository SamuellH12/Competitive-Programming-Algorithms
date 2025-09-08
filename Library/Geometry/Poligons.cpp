#include "Point.cpp" //LATEX_IGNORED_LINE
#include "Segment.cpp" //LATEX_IGNORED_LINE
using namespace std;

/*BLOCK_DESC_BEGIN 
Returns **twice area of a simple polygon**. area*2 (Shoelace Formula: signed cross product sum)
BLOCK_DESC_END*/
ll Area2x(vector<PT>& p){
  ll area = 0;  
  for(int i=2; i < p.size(); i++)
    area += (p[i]-p[0]) % (p[i-1]-p[0]);
  return abs(area);
}

/*BLOCK_DESC_BEGIN 
Returns if a point is **inside a triangle** (or in the border). 
BLOCK_DESC_END*/
bool ptInsideTriangle(PT p, PT a, PT b, PT c){
  if((b-a) % (c-b) < 0) swap(a, b);
  if(onSegment(a,b,p)) return 1;
  if(onSegment(b,c,p)) return 1;
  if(onSegment(c,a,p)) return 1;
  bool x = (b-a) % (p-b) < 0;
  bool y = (c-b) % (p-c) < 0;
  bool z = (a-c) % (p-a) < 0;
  return x == y && y == z;
}


/*BLOCK_DESC_BEGIN 
Returns the **center of mass for a polygon**. O(n) 
BLOCK_DESC_END*/
PT polygonCenter(const vector<PT>& v){
	PT res(0, 0); double A = 0;
	for(int i=0, j=v.size()-1; i<v.size(); j=i++){
		res = res + (v[i]+v[j]) * (v[j]%v[i]);
		A += v[j] % v[i];
	}
	return res / A / 3;
}


/*BLOCK_DESC_BEGIN
\begin{minipage}{0.85\textwidth}
**PolygonCut**: Returns the vertices of the polygon cut away at the left of the line s->e.
polygonCut(p, PT(0,0), PT(1,0));
\end{minipage}\hfill \begin{minipage}{0.15\textwidth} \includegraphics[height=4\baselineskip]{geometry/PolygonCut} \end{minipage} BLOCK_DESC_END*/

vector<PT> polygonCut(const vector<PT>& poly, PT s, PT e){
	vector<PT> res;
	for(int i=0; i<poly.size(); i++){
		PT cur = poly[i], prev = i ? poly[i-1] : poly.back();
		auto a = s.cross(e, cur), b = s.cross(e, prev);
		if((a < 0) != (b < 0)) res.push_back(cur + (prev - cur) * (a / (a - b)));
		if(a < 0) res.push_back(cur);
	}
	return res;
}

/*BLOCK_DESC_BEGIN 
Pick's theorem for **lattice points** in a simple polygon. (lattice points = integer points)
Area = insidePts + boundPts/2 - 1
2A - b + 2 = 2i
BLOCK_DESC_END*/
ll cntInsidePts(ll area_db, ll bound){ return (area_db + 2LL - bound)/2; }
ll latticePointsInSeg(PT a, PT b){
  ll dx = abs(a.x - b.x);
  ll dy = abs(a.y - b.y);
  return gcd(dx, dy) + 1;
}
