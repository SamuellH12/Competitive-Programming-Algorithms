#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 100010
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;

int n, buggy[MAXN], bits[MAXN];

void update(int pos, int val){
	for(; pos <= n; pos += pos & (-pos))
		bits[pos] += val;
}

int query(int pos){
	int resp = 0;
	for(; pos > 0; pos -= pos & (-pos))
		resp += bits[pos];
	return resp;
}


int main(){
	optimize;

	cin>>n;

	for(int i=1; i<=n; i++){
		cin>>buggy[i];
		update(i, buggy[i]);
	}

	char c; int i;

	while(cin>>c>>i)
	{
		if(c == 'a') 
		update(i, -buggy[i] );
		else 
		cout<<query(i-1)<<endl;
	}

	return 0;	
}
