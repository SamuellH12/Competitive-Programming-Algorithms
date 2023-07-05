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

//https://cses.fi/problemset/task/1693/

vector<int> grafo[MAXN];
vector<int> path;
int in[MAXN], out[MAXN], idx[MAXN];
int N, startVertex, noEdge;


void addEdge(int u, int v){
	grafo[u].push_back(v);	
	out[u]++;
	in[v]++;
}


bool isConnected(int s){

	vector<bool> vis (N, false);
	queue<int> fila;

	fila.push(s);
	vis[s] = true;
	int cnt = 1;

	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();

		for(auto v : grafo[u])
			if(!vis[v])
			{
				vis[v] = true;
				fila.push(v);
				cnt++;
			}
	}

	return cnt == N - noEdge;
}


bool hasEuler()
{
	int start = -1, end = -1;

	for(int i=0; i<N; i++)
	{
		if(!in[i] && !out[i]) noEdge++;
		if(in[i]  ==  out[i]) continue;

		if(in[i] - out[i] == -1 && start == -1) start = i;
		else
		if(in[i] - out[i] == 1  &&  end == -1 ) end = i;
		else 
			return false;
	}

	if(start == -1  && end != -1) return false;
	if(start != -1  && end == -1) return false;

	while(start == -1 && out[++start] == 0);
	startVertex = start;

	if(!isConnected(startVertex)) return false;

	return true;
}


void findPath(int u)
{
	while(idx[u] < grafo[u].size())
		findPath(grafo[u][idx[u]++]);
	
	path.push_back(u);
}




int main(){
	int m;
	cin >> N >> m;
	
	for(int i=0, u, v; i<m; i++)
	{
		cin >> u >> v;
		u--; v--;
		addEdge(u, v);
	}

	//cout << hasEuler() << endl;

	if(!hasEuler() || startVertex != 0){
		cout << "IMPOSSIBLE" << endl;
		//cerr << "aqui" << endl;
		return 0;
	}

	findPath(startVertex);

	reverse(ALL(path));

	if(path.back() != N-1)
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	for(auto x : path) cout << x + 1 << " "; 
	cout << endl;

	return 0;	
}
