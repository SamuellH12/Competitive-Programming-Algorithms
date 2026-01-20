#include "Point.cpp" //LATEX_IGNORED_LINE

// rotate the polygon such that the (bottom, left)-most point is at the first position
void reorder_polygon(vector<PT> &p){
    int j = 0;
    for(int i=1; i<p.size(); i++)
        if(pair(p[i].y, p[i].x) < pair(p[j].y, p[j].x)) 
            j = i;
    rotate(p.begin(), p.begin() + j, p.end());
}

vector<PT> minkowski(vector<PT> a, vector<PT> b){
    int n = a.size(), m = b.size(), i=0, j=0;
    reorder_polygon(a); reorder_polygon(b);
    a.push_back(a[0]); a.push_back(a[1]);
    b.push_back(b[0]); b.push_back(b[1]);
    
    vector<PT> c;
    while(i < n || j < m){
        c.push_back(a[i] + b[j]);
        auto p = (a[i+1] - a[i]) % (b[j+1] - b[j]);
        if(p >= 0) i++;
        if(p <= 0) j++;
    }
    return c;
}


/*LATEX_DESC_BEGIN***************************
**Minkowski Sum of convex polygons** - O(N)

@\begin{minipage}{0.85\textwidth}
Returns a convex hull of two polygons minkowski sum.  \\

The minkowski sum of polygons A and B is a polygon such that every vector 
inside it is the sum of a vector in A and a vector in B. \(A + B = C = \{a+b \mid a\in A,\; b\in B\}\) \\

min(a.size(), b.size()) >= 2

\end{minipage}\hfill \begin{minipage}{0.15\textwidth} 
\includegraphics[height=6\baselineskip]{geometry/minkowski} 
\end{minipage}@
*****************************LATEX_DESC_END*/