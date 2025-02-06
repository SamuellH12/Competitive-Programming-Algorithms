#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
const int MAXN = 1e6 + 5;
using namespace std;
// https://codeforces.com/gym/104767/problem/G

int pai[MAXN];

int find(int u){ return (pai[u] == u ? u : pai[u] = find(pai[u])); }

void join(int u, int v){
	u = find(u);
	v = find(v);
	pai[v] = u;
}

vector<pii> pts;
vector<pair<pii, pii>> arestas;

int get_id(int x, int y){
	auto it = lower_bound(ALL(pts), pii(x, y));
	if(it == pts.end() || *it != pii(x, y)) return -1;
	return it - pts.begin();
}

int get_id(pii a){ return get_id(a.first, a.second); }

int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};


int main(){
	for(int i=0; i<MAXN; i++) pai[i] = i;

	int n;
	cin >> n;

	for(int i=0, x1, y1, x2, y2; i<n; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		arestas.emplace_back(pii(x1, y1), pii(x2, y2));
		pts.emplace_back(x1, y1);
		pts.emplace_back(x2, y2);
	}

	sort(ALL(pts));
	pts.resize(unique(ALL(pts)) - pts.begin());	
	sort(ALL(arestas));
	int ans = 3;


	for(auto [p1, p2] : arestas)
	{
		//cerr << "ok ok -1 " << get_id(p1) << " " << get_id(p2) << endl;
		if(find(get_id(p1)) != find(get_id(p2)))
			join(get_id(p1), get_id(p2));
		else ans = 0;
	}

	auto existe_aresta = [&](pii a, pii b){
		pair<pii, pii> target(a, b);
		auto it = lower_bound(ALL(arestas), target);
		if(it == arestas.end() || *it != target) return false;
		return true;
	};


	vector<pii> pt2;
	set<pii> sla;
	set<pair<pii, pii>> conect_used;

	// cerr << "ok ok 0" << endl;

	for(auto [x, y] : pts){
		if(ans < 2) break;
		for(int i=0, x2, y2; i<4; i++)
		{
			x2 = x + dirx[i];
			y2 = y + diry[i];

			if(existe_aresta(pii(x, y), pii(x2, y2))) continue;
			if(existe_aresta(pii(x2, y2), pii(x, y))) continue;
			pt2.emplace_back(x2, y2);
			pt2.emplace_back(x, y); //inutil? Nop! 

			int id  = get_id(x , y );
			int id2 = get_id(x2, y2);

			if(id2 == -1) continue;
			
			auto conect_comp = pii(min(find(id), find(id2)), max(find(id), find(id2)));

			if(find(id) == find(id2)) ans = min(ans, 1);  //se eu adicionar essa nova aresta, eu consigo fechar um ciclo
			else
			if(sla.count(conect_comp) && !conect_used.count( make_pair(pii(x, y), pii(x2, y2))) ) ans = min(ans, 2); //se eu consegui adicionar outra aresta no passado que tb conecta esses dois componentes, eu fecho um ciclo
			else
				sla.insert(conect_comp),
				conect_used.insert(make_pair(pii(x, y), pii(x2, y2))),
				conect_used.insert(make_pair(pii(x2, y2), pii(x, y)));
		}
	}

	// cerr << "ok ok 1" << endl;
	// cerr << ans << endl;

	sort(ALL(pt2));
	pt2.resize(unique(ALL(pt2)) - pt2.begin());	

	for(auto [x, y] : pt2){
		if(ans <= 2) break;
		for(int i=0, x2, y2, x3, y3; i<4; i++)
			for(int j=0; j<4; j++){
				if(i == j) continue;

				x2 = x + dirx[i];
				y2 = y + diry[i];
				
				x3 = x + dirx[j];
				y3 = y + diry[j];

				if(existe_aresta(pii(x, y), pii(x2, y2))) continue;
				if(existe_aresta(pii(x2, y2), pii(x, y))) continue;
				if(existe_aresta(pii(x, y), pii(x3, y3))) continue;
				if(existe_aresta(pii(x3, y3), pii(x, y))) continue;

				int id2 = get_id(x2, y2);
				int id3 = get_id(x3, y3);

				// cerr << x << " " << y << " | " << x2 << " " << y2 << " " << " | " << x3 << " " << y3 << " // " << id2 << " " << endl;

				if(id2 == -1 || id3 == -1) continue;

				if(find(id2) == find(id3)) ans = min(ans, 2); //se eu adicionar 2 novas arestas, eu consigo fechar um ciclo
			}
	}


	cout << ans << endl;

	return 0;	
}
