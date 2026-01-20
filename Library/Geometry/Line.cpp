#include "Point.cpp" //LATEX_IGNORED_LINE

//if p is on line s to e
bool onLine(PT s, PT e, PT p){ return p.cross(s, e) == 0;}

/*BLOCK_DESC_BEGIN \begin{minipage}{0.85\textwidth}
 Returns the **signed dist** from p and the **line** of a and b.
 Positive value on left side and negative on right as seen from a->b. (a!=b)

\end{minipage}\hfill \begin{minipage}{0.15\textwidth} \includegraphics[height=4\baselineskip]{geometry/lineDistance} \end{minipage}
BLOCK_DESC_END*/

ld sLineDist(PT& a, PT& b, PT& p){ return a.cross(b, p) / (b-a).len(); }

/*BLOCK_DESC_BEGIN 
**Intersection between two lines**   \\
Unique   -> \{+1, pt\}               \\
No inter -> \{ 0, pt\}               \\
Infinity -> \{-1, pt\}           
May be rounded if inter isn't integer; Watch out for overflow if long long. 
BLOCK_DESC_END*/

pair<int, PT> lineInter(PT a, PT b, PT e, PT f){
	auto d = (b-a) % (f-e);
	if(d == 0) return {-(a.cross(b, e) == 0), PT()}; //parallel
	auto p = e.cross(b, f), q = e.cross(f, a);
	return {1, (a * p + b * q) / d};
}

/*BLOCK_DESC_BEGIN
**Projects point p onto line ab**. Set refl=true to get reflection of point p across line ab instead.
BLOCK_DESC_END*/

PT lineProj(PT a, PT b, PT p, bool refl=false) {
	PT v = b-a;
	return p - rotateCCW90(v) * (1+refl) * (v%(p-a)) / (v*v);
}