#include<bits/stdc++.h>
#define FastIO  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define FreOpen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define bigint int64_t
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define MAX INT_MAX
#define MIN INT_MIN
#define INF 1e18
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define vect vector<int>
#define pair_int pair<int,int>
#define paircout(x) cout<<"{"<<(x).first<<" "<<(x).second<<"}";
#define maxheap(T) priority_queue<T>
#define minheap(T) priority_queue<T,vector<T>,greater<T>>
#define mapofvector map<int,vector<int>>
#define mapofset map<int,set<int>>
#define Matrix(type) vector<vector<type>>
#define loop(i,a,b) for(ll i = a; i <= b; i++)
#define rloop(i,a,b) for(ll i = a; i >= b; i--)
#define loopSTL(itr,STL) for (auto itr = STL.begin(); itr != STL.end(); ++itr)
#define sq(a) (a)*(a)
#define NextPermutationSTL(STL) next_permutation(STL.begin(), STL.end())
#define NextPermutation(a,size) next_permutation(a,a+size)
//string tranform
#define lower(str) transform(str.begin(),str.end(),str.begin(),::tolower);
#define upper(str) transform(str.begin(),str.end(),str.begin(),::toupper);
#define lexcompare(str1,size1,str2,size2) lexicographical_compare(str1, str1+size1, str2, str2+size2)
//Modular Arthematics
#define MOD ((ll) 1e9 + 7)
#define MOD2 ((ll) 1e9 + 9)
#define ModAdd(a,b,N) 		((a)%(N) + (b)%(N))%(N);
#define ModSub(a,b,N) 		((a)%(N) - (b)%(N))%(N);
#define ModMultiply(a,b,N)	((a)%(N) * (b)%(N))%(N);
//extra
#define ceil_div(a,b) (a+b-1)/(b)
#define gcd(a,b) __gcd((long long int) a,(long long int) b)
using namespace std;

void distance(int src, int des, vector<vector<int>> adj, int now, int &ans, vector<bool> vis)
{
	vis[src] = 1;
	if (src == des)
	{
		ans = now;
		return;
	}

	for (auto v : adj[src]) if (!vis[v]) distance(v, des, adj, now + 1, ans, vis);
}

void Solve()
{
	int n, h; cin >> n >> h;

	vector<int> have(h); loop(i, 0, h - 1) cin >> have[i];

	sort(have.begin(), have.end());

	vector<vector<int>> adj(n + 1);
	loop(i, 1, n - 1)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<pair<int, pair<int, int>>> dis;

	loop(i, 0, h - 1)
	{
		loop(j, i + 1, h - 1)
		{
			int d = INT_MAX;
			vector<bool> vis(n + 1, 0);
			distance(have[i], have[j], adj, 0, d, vis);
			dis.push_back({d, {have[i], have[j]}});
		}
	}

	sort(dis.begin(), dis.end(), greater < pair<int, pair<int, int>>>());

	vector<bool> used(n + 1, 0);
	int ans = 0;
	for (auto x : dis)
	{
		pair<int, int> edge = x.second;
		if (used[edge.first] || used[edge.second]) continue;
		used[edge.first] = used[edge.second] = 1;
		ans += x.first;
	}

	cout << ans << endl;
}

int main(int argc, char const *argv[])
{

	FastIO;
	//FreOpen;
	int T = 1;
	//cin >> T;
	while (T--) Solve();
	return 0;
}