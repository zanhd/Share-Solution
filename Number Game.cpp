#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<vector<pair<ll, ll>>> go(vector<ll> a)
{
	vector<vector<pair<ll, ll>>> group;

	if (a.size() == 0) return group;

	for (ll i = 0; i < a.size(); i++)
	{
		for (ll j = 0; j < a.size(); j++)
		{
			if (i == j) continue;

			//choose this pair
			vector<ll> b;
			for (ll k = 0; k < a.size(); k++)
			{
				if (k == i || k == j) continue;
				b.push_back(a[k]);
			}

			vector<vector<pair<ll, ll>>> now = go(b);

			if (!now.size())
			{
				vector<pair<ll, ll>> x; x.push_back({a[i], a[j]});
				group.push_back(x);
			}
			else
			{
				for (auto x : now)
				{
					x.insert(x.begin(), {a[i], a[j]});
					group.push_back(x);
				}
			}
		}
	}

	return group;

}

int main()
{
	ll n; cin >> n;
	vector<ll> a(2 * n);
	for (ll i = 0; i < 2 * n; i++)
		cin >> a[i];

	vector < vector<pair<ll, ll>>> group = go(a);

	ll ans = 0;
	for (auto b : group)
	{
		ll now = 0;
		for (ll i = 0; i < b.size(); i++)
			now += __gcd(b[i].first, b[i].second) * (i + 1);
		ans = max(ans, now);
	}
	cout << ans;

	return 0;
}
