#include<bits/stdc++.h>
#define ModMultiply(a,b,N)	((a)%(N) * (b)%(N))%(N);
#define ll long long int
using namespace std;

//@zanhd
//Note : one of the best question on DP.

//inverse modulo : pow(a,-1) % m = pow(a,m - 2) % m : a and m should be coprime.
ll fastexpo(ll a, ll n, ll m)
{
	if (n == 1) return a;
	ll ans = fastexpo(a, n / 2, m);
	ans = ModMultiply(ans, ans, m);
	if (n & 1) ans = ModMultiply(ans, a, m);
	return ans;
}


int main()
{
	ll n, m; cin >> n >> m;
	bool a[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch; cin >> ch;
			a[i][j] = (ch == '#') ? 0 : 1;
		}
	}

	cout << endl;

	ll dp[n][m];
	dp[n - 1][m - 1] = 1;
	for (int j = m - 2; j >= 0; j--)
	{
		if (!a[n - 1][j]) dp[n - 1][j] = 0;
		else dp[n - 1][j] = dp[n - 1][j + 1];
	}

	for (int i = n - 2; i >= 0; i--)
	{
		if (!a[i][m - 1]) dp[i][m - 1] = 0;
		else dp[i][m - 1] = dp[i + 1][m - 1];
	}


	for (int i = n - 2; i >= 0; i--)
	{
		for (int j = m - 2; j >= 0; j--)
		{
			if (!a[i][j]) dp[i][j] = 0;
			else dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
		}
	}

	if (!dp[0][0]) { cout << 0 << endl; return 0; }


	ll pd[n][m];
	pd[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (!a[i][0]) pd[i][0] = 0;
		else pd[i][0] = pd[i - 1][0];
	}

	for (int j = 1; j < m; j++)
	{
		if (!a[0][j]) pd[0][j] = 0;
		else pd[0][j] = pd[0][j - 1];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (!a[i][j]) pd[i][j] = 0;
			else pd[i][j] = pd[i - 1][j] + pd[i][j - 1];
		}
	}

	ll freq = 0;
	ll special = 0;
	ll path = dp[0][0];
	for (int  i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!a[i][j]) continue;
			special++;
			if (dp[i][j] * pd[i][j] == path) freq++;
		}
	}

	ll M = 1e9 + 7;
	ll ans = freq * fastexpo(special, M - 2, M);
	cout << ans % M << endl;
}

