#include "Point.cpp" //LATEX_IGNORED_LINE

//if p is on segment s to e
bool onSegment(PT s, PT e, PT p){ 
	return p.cross(s, e) == 0 && (s-p) * (e-p) <= 0;
}

/*BLOCK_DESC_BEGIN \begin{minipage}{0.85\textwidth}
Returns the shortest **distance** between point p and the **segment** s->e.

\end{minipage}\hfill \begin{minipage}{0.15\textwidth} \includegraphics[height=4\baselineskip]{geometry/SegmentDistance} \end{minipage}
BLOCK_DESC_END*/

ld segmentDist(PT& s, PT& e, PT& p){
	if (s==e) return (p-s).len();
	ld d = (e-s)*(e-s);
  ld t = min(d, max<ld>(0, (p-s)*(e-s)));
	return ((p-s)*d - (e-s)*t).len() / d;
}

/*BLOCK_DESC_BEGIN 
**Segment intersection** \\
Unique   -> \{p\}        \\
No inter -> \{ \}        \\
Infinity -> \{a, b\}, the endpoints of the common segment.
May be rounded if inter isn't integer; Watch out for overflow if long long. BLOCK_DESC_END*/

int sgn(ll x){ return (x>0) - (x<0); }
vector<PT> segInter(PT a, PT b, PT c, PT d){
	auto oa = c.cross(d, a), ob = c.cross(d, b);
	auto oc = a.cross(b, c), od = a.cross(b, d);
	if(sgn(oa)*sgn(ob) < 0 && sgn(oc)*sgn(od) < 0) 
		return {(a*ob - b*oa) / (ob-oa)};
	set<PT> s;
	if(onSegment(c, d, a)) s.insert(a);
	if(onSegment(c, d, b)) s.insert(b);
	if(onSegment(a, b, c)) s.insert(c);
	if(onSegment(a, b, d)) s.insert(d);
	return {begin(s), end(s)};
}

