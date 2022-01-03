#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> seive(ll n = 1e7 + 5)
{
	vector<ll> prime;

	bool IsPrime[n];
	for (ll i = 2; i <= n; i++)
		IsPrime[i] = 1;

	for (ll i = 2; i * i <= n; ++i)
	{
		if (!IsPrime[i]) continue;
		for (ll j = i * i; j <= n; j += i)
		{
			IsPrime[j] = 0;
		}
	}

	for (ll i = 2; i <= n; i++)
		if (IsPrime[i])
			prime.push_back(i);
	return prime;
}

int main()
{
	vector<ll> Prime = seive(1e5 + 5);

	ll T; cin >> T;
	while (T--)
	{
		ll a, b; cin >> a >> b;
		ll ans = a + b - 1;
		vector<ll> one, two;
		for (auto x : Prime)
		{
			if (x <= a) one.push_back(x);
			if (x <= b) two.push_back(x);
		}

		for (auto x : one)
		{
			if (x <= two.back()) ans += two.size() - 1;
			else ans += two.size();
		}

		cout << ans << endl;
	}
	return 0;
}
