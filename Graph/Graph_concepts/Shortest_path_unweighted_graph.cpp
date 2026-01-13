#include <bits/stdc++.h>
using namespace std;

// method 1 with visited matrix and pair for step claculation

int row[4] = {1, -1, 0, 0};
int col[4] = {0, 0, 1, -1};

int shortestPathUnweightGraph1(vector<vector<int>> &A, int X, int Y)
{
    queue<pair<int, pair<int, int>>> q;
    int m = A.size();
    int n = A[0].size();

    // edge cases
    if (A[0][0] == 0)
    {
        return -1;
    }
    if (X == 0 && Y == 0)
    {
        return 0;
    }
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    q.push({0, {0, 0}});
    vis[0][0] = true;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second.first;
        int stp = q.front().second.second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ni = i + row[k];
            int nj = j + col[k];
            if (ni >= 0 && nj >= 0 && ni < m && nj < n && A[ni][nj] == 1 && !vis[ni][nj])
            {
                if (ni == X && nj == Y)
                {
                    return stp + 1;
                }
                q.push({ni, {nj, stp + 1}});
                vis[ni][nj] = true;
            }
        }
    }
    return -1;
}

// method 2 means without visited matrix and with putting pairs in queue;
int shortestPathUnweightGraph2(vector<vector<int>> &A, int X, int Y)
{
    queue<pair<int, int>> q;
    int m = A.size();
    int n = A[0].size();

    // edge cases
    if (A[0][0] == 0)
    {
        return -1;
    }
    if (X == 0 && Y == 0)
    {
        return 0;
    }
    //vector<vector<bool>> vis(m, vector<bool>(n, false));
    q.push({0, 0});
    //vis[0][0] = true;
    A[0][0]=0;
    int step = 0;
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int ni = i + row[k];
                int nj = j + col[k];
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && A[ni][nj] == 1 )
                {
                    if (ni == X && nj == Y)
                    {
                        return step + 1;
                    }
                    q.push({ni,nj});
                    A[ni][nj]=0;
                    //vis[ni][nj] = true;
                }
            }
        }
        step++;
    }
    return -1;
}

int main()
{
    vector<vector<int>> A = {{1, 1, 1, 0}, {1, 0, 1, 0}, {1, 0, 1, 1}, {1, 0, 0, 1}, {1, 1, 1, 1}};
    int X = 4;
    int Y = 2;
    int steps = shortestPathUnweightGraph2(A, X, Y);
    cout << "minimum no. of step to reach destination: " << steps << endl;
}