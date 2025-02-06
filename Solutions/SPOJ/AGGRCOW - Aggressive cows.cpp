#include <bits/stdc++.h>
#define optimize                 \
	ios::sync_with_stdio(false); \
	cin.tie(NULL);               \
	cout.tie(NULL)
#define ALL(x) x.begin(), x.end()
#define endl "\n"
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define MAXN 110
#define INF 0x3f3f3f3f
#define debug cerr << "ate aqui ok\n"
using namespace std;
//https://www.spoj.com/problems/AGGRCOW/en/

vi pos;
int n, c;

bool ok(int dist)
{
	int last = -INF, qtd = 0;

	for(auto x : pos)
	{
		if( x - last >= dist)
		{
			qtd++;
			last = x;
		}
	}

	return qtd >= c;
}

int main()
{

	int casos;
	cin >> casos;

	while (casos--)
	{

		cin >> n >> c;

		pos.resize(n);

		for (auto &x : pos)
		{
			cin >> x;
		}

		sort(ALL(pos));

		int l = 0, r = 1'000'000'010, mid, ans = 0;
		while (l <= r)
		{

			mid = (l + r) / 2;

			if (ok(mid))
			{
				ans = max(mid, ans);

				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}

		cout << ans << endl;
	}

	return 0;
}

//https://vjudge.net/contest/478045#problem/C