#include <bits/stdc++.h>
using namespace std;

// using dfs
void dfs_Island(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0' || vis[i][j])
        return;

    vis[i][j] = true;

    dfs_Island(i + 1, j, vis, grid, m, n);
    dfs_Island(i, j - 1, vis, grid, m, n);
    dfs_Island(i, j + 1, vis, grid, m, n);
    dfs_Island(i - 1, j, vis, grid, m, n);
}

int no_Island(vector<vector<char>> &grid)
{
    int island = 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                dfs_Island(i, j, vis, grid, m, n);
                island++;
            }
        }
    }
    return island;
}

// using bfs
int row[4] = {-1, 0, 1, 0};
int col[4] = {0, -1, 0, 1};
void bfsHelper(int i, int j, vector<vector<bool>> &vis, vector<vector<char>> &grid, int m, int n)
{
    queue<pair<int, int>> q;
    vis[i][j] = true;
    q.push({i, j});
    while (q.size() > 0)
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int ni = x + row[k];
            int nj = y + col[k];
            if (ni >= 0 && nj >= 0 && ni < m && nj < n && !vis[ni][nj] && grid[ni][nj] == '1')
            {
                vis[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
}

int bfsIsland(vector<vector<char>> &gridmatrix)
{

    int count = 0;
    int m = gridmatrix.size();
    int n = gridmatrix[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && gridmatrix[i][j] == '1')
            {
                bfsHelper(i, j, vis, gridmatrix, m, n);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<char>> gridmatrix = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}};
    cout << "No of Island using DFS :  " << no_Island(gridmatrix) << endl;
    cout << "No of Island using BFS :  " << bfsIsland(gridmatrix) << endl;
}