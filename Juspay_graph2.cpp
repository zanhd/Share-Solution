#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void bfs(ll src, unordered_map<ll, vector<ll>> adj, vector<ll>& ans)
{
	queue<ll> Q;
	Q.push(src);
	ans[src] = 0;
	while (!Q.empty())
	{
		ll u = Q.front(); Q.pop();
		for (auto v : adj[u])
		{
			if (ans[v] != -1) continue;
			Q.push(v);
			ans[v] = ans[u] + 1;
		}
	}
}

int main()
{
	ll T; cin >> T;
	while (T--)
	{
		ll n; cin >> n;
		ll edge[n];
		for (ll i = 0; i < n; i++)
			cin >> edge[i];

		ll x, y; cin >> x >> y;

		unordered_map<ll, vector<ll>> adj;
		for (ll i = 0; i < n; i++)
		{
			adj[i].push_back(edge[i]);
		}

		vector<ll> a(n, -1);
		bfs(x, adj, a);
		vector<ll> b(n, -1);
		bfs(x, adj, b);

		ll ans = -1;
		pair<ll, ll> d = { -1, -1};
		for (ll i = 0; i < n; i++)
		{
			if (a[i] == -1 || b[i] == -1) continue;

			if (ans == -1)
			{
				ans = i;
				d = {a[i], b[i]};
			}
			else
			{
				if (a[i] <= d.first && b[i] <= d.second)
				{
					ans = i;
					d = {a[i], b[i]};
				}
			}
		}

		cout << ans << endl;


	}
	return 0;
}
