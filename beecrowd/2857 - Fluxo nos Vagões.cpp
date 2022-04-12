#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 100010
#define INF 0x3f3f3f3f
#define debug cout<<"ate aqui ok\n"
using namespace std;

int n, m;//, bit[MAXN];
vector<int> bit; 

void update(int pos, int sum)
{
	for(; pos < n; pos += pos & (-pos))
		bit[pos] += sum;
}

int query(int pos)
{
	int resp=0;
	for(; pos > 0; pos -= pos & (-pos))
		resp += bit[pos];
	return resp;
}


int main(){
	optimize;
	cin>>n>>m; n++;

	bit = vi (n, 0);

	while(m--)
	{
		int atv; cin>>atv;

		if(atv == 1)
		{
			int v, y;
			cin>>v>>y;
			update(v, y);
		}
		else
		{
			int a, b, c, d, resp = 0;
			cin>>a>>b>>c>>d;
			
			if( b < c || d < a ) //a-b c-d // c-d a-b não se intersectam
			{
				resp = query(b) - query(a - 1);
				resp += query(d) - query(c - 1);

				cout << resp << endl;
			}
			else // está contido
			{
				int min = ( a < c ? query(a - 1) : query(c - 1) );
				int max = ( b < d ? query(d) : query(b) );

				cout << max - min << endl;
			}

		}
	}

	return 0;	
}

//https://www.beecrowd.com.br/judge/pt/problems/view/2857