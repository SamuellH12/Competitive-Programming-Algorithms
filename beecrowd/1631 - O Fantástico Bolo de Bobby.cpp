#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;

struct pt {

	int x, y;

	pt(int x_ = 0, int y_ = 0){ x = x_; y = y_; }

	bool operator <  (const pt p) const { if(x != p.x) return x < p.x;  return y < p.y; }
	bool operator == (const pt p) const { return x == p.x && y == p.y; }

	pt operator + (const pt p) const { return pt(x+p.x, y+p.y);   }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y);   }
	pt operator * (const int i)const { return pt(x*i, y*i);       }
	ll operator * (const pt p) const { return x*(ll)p.x+y*(ll)p.y;}
	ll operator ^ (const pt p) const { return x*(ll)p.y-y*(ll)p.x;}
};

struct line {
	pt p, q;

	line(pt p_=0, pt q_=0) : p(p_), q(q_) {}
};


int n;
vector<pt> pontos;

ll signedTwoArea(pt p, pt q, pt r) //area do triangulo com sinal
{
	return (q-p) ^ (r-q);
}

ll pow2Dist(pt p, pt q) //a distancia entre dois pontos (mas ainda elevada ao quadrado,  distancia real é a raiz disso)
{
	return (ll) (p.x-q.x)*(p.x-q.x)  +  (ll) (p.y-q.y)*(p.y-q.y);
}

double disttoline(line l, pt p)
{
	return signedTwoArea(l.p, l.q, p) / sqrt( pow2Dist(l.p, l.q) );
}

double distLineGLOBAL(line l)
{
	double distE = 0, distD = 0;

	for(int i=0; i<n; i++)
	{
		double x = disttoline(l, pontos[i]);
		if(x < 0) distD += x;
		else distE += x;
	}

	return abs(distE + distD);
}


int main()
{	optimize;

	cout<<fixed<<setprecision(3);
	
	while(cin>>n && n > 0)
	{
		double resp = INF;
		pontos.clear();

		for(int i=0, x, y; i<n; i++)
		{
			cin>>x>>y;
			pontos.push_back( pt(x, y) );
		}

		for(int i=0; i<n; i++)
		{
			for(int e=i+1; e<n; e++)
			{
				resp = min( resp, distLineGLOBAL(line(pontos[i], pontos[e]))  );
			}
		}

		cout<<resp<<endl;
	}

	return 0;	
}


//https://www.beecrowd.com.br/judge/pt/problems/view/1631?origem=1