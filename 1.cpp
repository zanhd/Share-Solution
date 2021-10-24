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

//Time Complexity : O(T * E * (V + E))

bool dfs(int src, int des, vector<vector<int>> adj, int days, vector<int> vis)
{
	vis[src] = 1;

	if (days == 0)
	{
		if (src == des) return 1;
		return 0;
	}

	for (auto v : adj[src])
	{
		if (vis[v]) continue;
		if (dfs(v, des, adj, days - 1, vis)) return 1;
	}

	return 0;
}


int miniDurability(int n, int m, vector<int> from, vector<int> to, vector<int> temperature, int src, int des, int days)
{
	vector<pair<int, pair<int, int>>> edge(m + 1);
	loop(i, 0, m - 1) edge[i] = {temperature[i], {from[i], to[i]}};

	sort(edge.begin(), edge.end());

	int ans = INT_MAX;

	vector<vector<int>> adj(n + 1);
	for (auto x : edge)
	{
		ans = x.first;
		vector<int> vis(n + 1, 0);
		adj[x.second.first].push_back(x.second.second);
		if (!dfs(src, des, adj, days, vis)) continue;
		break;
	}

	return ans;
}

void Solve()
{
	int n, m; cin >> n >> m;
	vector<int> from(m);
	vector<int> to(m);
	vector<int> temperature(m);
	loop(i, 0, m - 1) cin >> from[i] >> to[i] >> temperature[i];

	int s, t, d; cin >> s >> t >> d;

	cout << miniDurability(n, m, from, to, temperature, s, t, d) << endl;
}

int main(int argc, char const *argv[])
{

	FastIO;
	//FreOpen;
	int T = 1;
	cin >> T;
	while (T--) Solve();
	return 0;
}