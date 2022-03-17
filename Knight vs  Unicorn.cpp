#include <bits/stdc++.h>
using namespace std;

// define
#define KNIGHT 0
#define UNICORN 1

void output(int test, int ans)
{
    cout << "#" << test << " " << ans << endl;
}

pair<int, int> move(pair<int, int> now, int dir)
{
    int i = now.first, j = now.second;
    switch (dir)
    {
    case 0:
        return {i - 2, j + 1};
    case 1:
        return {i - 2, j - 1};
    case 2:
        return {i - 1, j - 2};
    case 3:
        return {i + 1, j - 2};
    case 4:
        return {i + 2, j - 1};
    case 5:
        return {i + 2, j + 1};
    case 6:
        return {i + 1, j + 2};
    case 7:
        return {i - 1, j + 2};
    }

    return {-1, -1};
}

pair<int, int> move(pair<int, int> now, int dir, int steps)
{
    if (steps == 1)
        return move(now, dir);

    return move(move(now, dir), dir, steps - 1);
}

bool isgood(pair<int, int> now, int n)
{
    return (now.first > 0 && now.second > 0 && now.first <= n && now.second <= n);
}

int bfs(int n, int i, int j, int ides, int jdes, int player)
{
    vector<vector<int>> level(n + 1, vector<int>(n + 1, -1));

    queue<pair<int, int>> Q;
    Q.push({i, j});
    level[i][j] = 0;

    while (!Q.empty())
    {
        pair<int, int> u = Q.front();
        Q.pop();

        // go to neighbours
        if (player == KNIGHT)
        {
            for (int dir = 0; dir <= 7; dir++)
            {
                pair<int, int> v = move(u, dir, 1);
                if ((!isgood(v, n)) || level[v.first][v.second] != -1)
                    continue;
                Q.push(v);
                level[v.first][v.second] = level[u.first][u.second] + 1;
            }
        }
        else
        {
            for (int dir = 0; dir <= 7; dir++)
            {
                for (int steps = 1; steps <= 3; steps++)
                {
                    pair<int, int> v = move(u, dir, steps);
                    if ((!isgood(v, n)) || level[v.first][v.second] != -1)
                        continue;
                    Q.push(v);
                    level[v.first][v.second] = level[u.first][u.second] + 1;
                }
            }
        }
    }

    return level[ides][jdes];
}

int solve()
{
    int n, ur, uc, pr, pc;
    cin >> n >> ur >> uc >> pr >> pc;

    int unicorn_move = bfs(n, ur, uc, pr, pc, UNICORN);
    int knight_move = bfs(n, ur, uc, pr, pc, KNIGHT);

    return knight_move - unicorn_move;
}

int main()
{
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
        output(i, solve());
}
