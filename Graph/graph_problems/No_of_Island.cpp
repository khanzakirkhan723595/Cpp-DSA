#include<bits/stdc++.h>
using namespace std;

void dfs_Island(int i,int j,vector<vector<bool>> &vis, vector<vector<char>> &grid,int m,int n)
{
    if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0' || vis[i][j])
        return;

    vis[i][j]=true;
    
    dfs_Island(i+1,j,vis,grid,m,n);
    dfs_Island(i,j-1,vis,grid,m,n);
    dfs_Island(i,j+1,vis,grid,m,n);
    dfs_Island(i-1,j,vis,grid,m,n);
}

int no_Island(vector<vector<char>> &grid)
{
    int island=0;
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<bool>> vis(m,vector<bool> (n,false));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!vis[i][j] && grid[i][j]=='1')
            {
                dfs_Island(i,j,vis,grid,m,n);
                island++;
            }
        }
    }
    return island;

}

int main()
{
    vector<vector<char>> gridmatrix={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','1','0','0'}};
    cout<<"No of Island :  "<<no_Island(gridmatrix)<<endl;
}