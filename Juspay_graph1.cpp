#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll T; cin >> T;
	while (T--)
	{
		ll n; cin >> n;
		ll edge[n];
		for (ll i = 0; i < n; i++)
			cin >> edge[i];

		ll sum[n] = {0};
		for (ll  i = 0; i < n; i++)
		{
			if (edge[i] == -1) continue;
			sum[edge[i]] += i;
		}

		ll ans = 0;
		for (ll  i = 0; i < n; i++)
			ans = max(ans, sum[i]);

		for (ll i = 0; i < n; i++)
		{
			if (ans != sum[i]) continue;
			cout << i << endl;
			break;
		}

	}
	return 0;
}
