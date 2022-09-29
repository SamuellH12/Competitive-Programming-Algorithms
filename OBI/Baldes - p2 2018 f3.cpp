#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define debug cerr<<"ate aqui ok\n"
using namespace std;

pii seg[4*MAXN];
int n, m;
int mn[MAXN], mx[MAXN]; 


pii query(int no, int l, int r, int a, int b)
{
	if( b < l || r < a ) return {0, 0};
	if( a<= l && r <= b ){ return seg[no];}

	int mid = (l+r)/2;
	int esq = no*2;
	int dir = esq+1;

	pii es = query(esq, l, mid, a, b);
	pii di = query(dir, mid+1, r, a, b);

	return  make_pair( (mx[es.first] > mx[di.first] ? es.first :di.first ), (mn[es.second] < mn[di.second] ? es.second: di.second));
}


void update(int no, int l, int r, int i, int v)
{
	if( i < l || r < i ) return;
	if(l == r)
	{  
		if(v > mx[i]){
			seg[no].first = i;  mx[i] = v;
		}
		if(v < mn[i] || mn[i] == 0){
			seg[no].second = i;	mn[i] = v;
		}
		return;
	}

	int mid = (l+r)/2;
	int esq = no*2;
	int dir = esq+1;

	update(esq,   l, mid, i, v);
	update(dir, mid+1, r, i, v);

	seg[no].first = (mx[seg[esq].first]  > mx[seg[dir].first]  ? seg[esq].first : seg[dir].first );
	seg[no].second= (mn[seg[esq].second] < mn[seg[dir].second] ? seg[esq].second: seg[dir].second);
}

//1   2  3  4   5  6 7 8     9 10
//3 15_9 12 4 20_1 5 7 33_15 9 10

int main(){
	cin >> n >> m;
	mn[0] = INF; mx[0] = -INF;


	for(int i=1, x; i<=n; i++)
	{
		cin >> x;
		update(1, 1, n, i, x);
	}

	while(m--)
	{

		int c, a, b;
		cin >> c >> a >> b;

		if( c == 1)
		{
			update(1, 1, n, b, a);
		}
		else
		{
			pii aux = query(1, 1, n, a, b); //pego o indice do min e max na seg

			//se os indices forem diferentes, achei a resp:
			if(aux.first != aux.second)
				cout << mx[aux.first] -  mn[aux.second] << endl;
			else
			{
				int i = aux.first;
				int gt = mx[i], ls = mn[i], resp = 0;

				if(i > a){ //ao menos 2 baldes (se a==1 e i == 1, não posso procurar [1,0])
					aux = query(1, 1, n, a, i-1);
					resp = max( gt-mn[aux.second], mx[aux.first]-ls );
				}

				if(i < b){	//mesma coisa do anterior
					aux = query(1, 1, n, i+1, b);
					resp = max( {gt-mn[aux.second], mx[aux.first]-ls, resp} );
				}

				cout << resp << endl;

			}
		}

	}
	
	return 0;	
}
