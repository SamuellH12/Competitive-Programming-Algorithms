#include "Point.cpp" //LATEX_IGNORED_LINE
#include "Segment.cpp" //LATEX_IGNORED_LINE
using namespace std;

/*LATEX_DESC_BEGIN***************************
@\begin{minipage}{0.35\textwidth}
Given a vector of points, return the convex hull in CCW order. \\
A convex hull is the smallest convex polygon that contains all the points.
\end{minipage}\hfill \begin{minipage}{0.05\textwidth} \includegraphics[height=4\baselineskip]{geometry/ConvexHull} \end{minipage} @ 

If you want colinear points in border, change the >=0 to >0 in the while's. 
**WARNING:**if collinear and all input PT are collinear, may have duplicated points (the round trip)
*****************************LATEX_DESC_END*/

vector<PT> ConvexHull(vector<PT> pts, bool sorted=false){
	if(!sorted) sort(begin(pts), end(pts));
	pts.resize(unique(begin(pts), end(pts)) - begin(pts));
	if(pts.size() <= 1) return pts;

	int s=0, n=pts.size();
	vector<PT> h(2*n+1);

	for(int i=0; i<n; h[s++] = pts[i++])
		while(s > 1 && (pts[i] - h[s-2]) % (h[s-1] - h[s-2]) >= 0 )
			s--;

	for(int i=n-2, t=s; ~i; h[s++] = pts[i--])
		while(s > t && (pts[i] - h[s-2]) % (h[s-1] - h[s-2]) >= 0 )
			s--;

	h.resize(s-1);
	return h;
} //PT operators needed: {- % == <}

/*BLOCK_DESC_BEGIN Check **if a point is inside convex hull** (CCW, no collinear). 
If strict == true, then pt on boundary return false
O(log N)
BLOCK_DESC_END*/
bool isInside(const vector<PT>& h, PT p, bool strict = true){
	int a = 1, b = h.size() - 1, r = !strict;
	if(h.size() < 3) return r && onSegment(h[0], h.back(), p);
	if(h[0].cross(h[a], h[b]) > 0) swap(a, b);
	if(h[0].cross(h[a], p) >= r || h[0].cross(h[b], p) <= -r) return false;
	while(abs(a-b) > 1){
		int c = (a + b) / 2;
		if(h[0].cross(h[c], p) > 0) b = c;
		else a = c;
	}
	return h[a].cross(h[b], p) < r;
}

/*BLOCK_DESC_BEGIN Check **if a point is inside convex hull** \\ O(log N) BLOCK_DESC_END*/
bool isInside(const vector<PT> &h, PT p){
	if(h[0].cross(p, h[1]) > 0 || h[0].cross(p, h.back()) < 0) return false;
    int n = h.size(), l=1, r = n-1;
    while(l != r){
        int mid = (l+r+1)/2;
        if(h[0].cross(p, h[mid]) < 0) l = mid;
        else r = mid - 1;
    }
    return h[l].cross(h[(l+1)%n], p) >= 0;
} 


/*BLOCK_DESC_BEGIN 
Given a convex hull h and a point p, returns the indice of h **where the dot product is maximized**.
This code assumes that there are NO 3 colinear points!
BLOCK_DESC_END*/
int maximizeScalarProduct(const std::vector<PT> &h, PT v) {
    int ans = 0, n = h.size();
    if(n < 20){
		for(int i=0; i<n; i++)
            if(v*h[ans] < v*h[i])
                ans = i;
		return ans;
    }
	
	for(int rep=0; rep<2; rep++){
		int l = 2, r = n-1;
		while(l != r){
			int mid = (l+r+1)/2;
			int f = v*h[mid] >= v*h[mid-1];

			if(rep) f |= v*h[mid-1] < v*h[0];
			else    f &= v*h[mid]  >= v*h[0];

			if(f) l = mid;
			else  r = mid - 1;
		}
		if(v*h[ans] < v*h[l]) ans = l;
	}
	if(v*h[ans] < v*h[1] ) ans = 1;
	return ans;
}