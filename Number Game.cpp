#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int dp[8][16384] = {};
int maxScore(vector<int>& a, int i = 1, int mask = 0) {
	if (i > a.size() / 2)
		return 0;
	if (!dp[i][mask])
		for (int j = 0; j < a.size(); ++j)
			for (auto k = j + 1; k < a.size(); ++k) {
				int new_mask = (1 << j) + (1 << k);
				if ((mask & new_mask) == 0)
					dp[i][mask] = max(dp[i][mask], i * __gcd(a[j], a[k]) + maxScore(a, i + 1, mask + new_mask));
			}
	return dp[i][mask];
}

int main()
{
	int n; cin >> n;
	vector<int> a(2 * n);
	for (int i = 0; i < 2 * n; i++)
		cin >> a[i];

	cout << maxScore(a) << endl;

	return 0;
}
