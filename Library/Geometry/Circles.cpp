#include "Point.cpp" //LATEX_IGNORED_LINE
using namespace std;

/*BLOCK_DESC_BEGIN
\begin{minipage}{0.9\textwidth}
The **circumcirle of a triangle** is the circle intersecting all three vertices.
\end{minipage}\hfill \begin{minipage}{0.1\textwidth} \includegraphics[height=2\baselineskip]{geometry/circumcircle} \end{minipage} BLOCK_DESC_END*/
double ccRadius(PT& A, PT& B, PT& C) {
	return (B-A).len()*(C-B).len()*(A-C).len() / abs(A.cross(B, C))/2; 
}
PT ccCenter(PT& A, PT& B, PT& C) {
	PT b = C-A, c = B-A;
	return A + rotateCCW90(b*(c*c) - c*(b*b)) / (b%c) / 2;
}


/*BLOCK_DESC_BEGIN Return the points at **two circles intersection**. If none or infinity, returns empty BLOCK_DESC_END*/
vector<PT> circleCircleInter(PT a, ld r1, PT b, ld r2){
  if (a == b) return {}; //r1==r2? infinity : none
	PT v = b-a;
	
  ld d2 = v*v, sum = r1+r2, dif = r1-r2;
  ld p = (d2 + r1*r1 - r2*r2) / (d2+d2), h2 = r1*r1 - p*p*d2;

	if(sum*sum < d2 || dif*dif > d2) return {};
	
  PT mid=a+v*p, per=rotateCCW90(v)*sqrt(fmax(0, h2) / d2);

	set<PT> ans = {mid + per, mid - per};
	return {begin(ans), end(ans)};
}

/*BLOCK_DESC_BEGIN Return the **circle line intersection**. Return a vector of 0,1 or 2 PTs BLOCK_DESC_END*/
vector<PT> circleLineInter(PT c, ld r, PT a, PT b){
  PT ab = b-a;
  PT p = a + ab * ((c-a)*ab) / (ab*ab);
  ld s = a.cross(b, c);
  ld h2 = r*r - s*s / (ab*ab);
  if(h2 < 0) return {};
  if(h2 == 0) return {p};
  PT h = ab/ab.len() * sqrt(h2);
  return {p - h, p + h};
}

/*BLOCK_DESC_BEGIN Returns the **minimum enclosing circle** for a set of points. Expected O(n) BLOCK_DESC_END*/
pair<PT, ld> minEnclose(vector<PT> ps) {
	shuffle(begin(ps), end(ps), mt19937(time(0)));
	PT o = ps[0];
	ld r=0, EPS = 1 + 1e-8;

	for(int i=0; i<ps.size(); i++) if(dist(o, ps[i]) > r*EPS){
    o = ps[i], r = 0;

		for(int j=0; j<i; j++) if(dist(o, ps[j]) > r*EPS){
      o = (ps[i] + ps[j]) / 2;
      r = dist(o, ps[i]);
      
      for(int k=0; k<j; k++) if(dist(o, ps[k]) > r*EPS){
        o = ccCenter(ps[i], ps[j], ps[k]);
        r = (o - ps[i]).len();
      }
    }
	}
	
  return {o, r};
}