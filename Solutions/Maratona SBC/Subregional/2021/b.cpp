#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<ll,ll>
#define INF 0x3f3f3f3f
using namespace std;


// B. Beautiful Words
// https://codeforces.com/gym/103388/problem/B

 
const ll MOD=1200000961;//big prime number
const int mod=1227090031;
const ll base=157;//random number larger than the size of the alphabet
const int maxn=1e6+10;
 
 
int expBase[maxn];
int expBase2[maxn];
 
void precalc(){
    expBase[0]=1;
    expBase2[0]=1;
    for (int i=1;i<maxn;i++){
        expBase[i]=(expBase[i-1]*base)%MOD;
        expBase2[i]=(expBase2[i-1]*base)%mod;
    }
}
 
struct StringHash{
    vector<pair<ll,ll>> hsh;
	int size;
    //REMEMBER TO RUN PRECALC
    StringHash(string& _s){
        hsh=vector<pair<ll,ll>>(_s.length()+1,{0,0});
		size = _s.length();
        for (int i=0;i<_s.length();i++){
            hsh[i+1].first=((hsh[i].first*base)%MOD + _s[i])%MOD;
            hsh[i+1].second=((hsh[i].second*base)%mod + _s[i])%mod;
        }
    }
 
    //interval =  [a,b] closed
    pair<ll,ll> getKey(int a,int b){
        auto p1= (MOD + hsh[b+1].first - ((hsh[a].first)*expBase[b-a+1])%MOD)%MOD;
        auto p2= (mod + hsh[b+1].second - ((hsh[a].second)*expBase2[b-a+1])%mod)%mod;
        return {p1,p2};
    }
    
};
 


int main(){
    precalc();

    int n, m;
    cin >> n >> m;

    string a, b; 
    
    cin >> a;
    a += a;
    StringHash hs (a);


    vector<StringHash> sh;

    for(int i=0; i<m; i++){   
        cin >> b;
        sh.emplace_back(b);
    }


    int l=1, r=n, mid, ans = n+1;

    while(l <= r)
    {
        mid = (l+r)/2;

        set<pii> s;

        for(int i=0; i<m; i++)
            for(int j=0; j+mid<=sh[i].size; j++)
                s.insert( sh[i].getKey(j, j+mid-1) );

        
        int lst = 0, ok = false;


        for(int i=0; i+mid<=n+n && !ok; i++)
        {
            if(s.find(hs.getKey(i, i+mid-1)) != s.end()) 
                lst = i;

            if( i - lst + mid > n  ) 
                ok = true;
        }


        if(ok) r = mid-1, ans = mid;
        else   l = mid+1;
    }


    cout << ans-1 << endl;

    return 0;
}