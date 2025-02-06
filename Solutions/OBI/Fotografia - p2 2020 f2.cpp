#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define MAXN 110
#define INF 10000010
#define debug cout<<"ate aqui ok\n"
using namespace std;

  

int main(){

	int fa, fb, n, melhor = -1, melhora = INF;
	cin>>fa>>fb>>n;

	for(int i=1; i<=n; i++){
		int ma, mb;
		cin>>ma>>mb;

		if((fa>ma || fb>mb) && (fb>ma || fa>mb)) continue;

		int area;
		
		area = (ma*mb)-(fa*fb);

		if(melhor!=-1 && area < melhora){
			melhor = i; melhora = area;
		} else if(melhor==-1){
			melhor = i; melhora = area;
		}

	}

	cout<<melhor<<endl;

	return 0;	
}
