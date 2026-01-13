#include<bits/stdc++.h>
using namespace std;


int rottingOrange(vector<vector<int>>&grid)
{
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<bool>> vis(m,vector<bool>(n,false));
    queue<pair<int,int>> q;
    int fresh=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({i,j});
            }
            else if(grid[i][j]==1)
            {
                fresh++;
            }
        }
    }

    int row[m]={1,-1,0,0};
    int col[n]={0,0,1,-1};
    int time=0;
    while(q.size()>0 && fresh>0)
    {
        int sz=q.size();
        time++;
        while(sz--)
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(int k=0;k<4 ; k++)
            {
                int ni=i+row[k];
                int nj=j+col[k];
                if(ni>=0 && nj>=0 && ni<m && nj<n && !vis[ni][nj] && grid[ni][nj]==1)
                {
                    vis[ni][nj]=true;
                    q.push({ni,nj});
                    fresh--;
                }
            }
        }
        
        
    }
    return fresh==0 ? time : -1;
}

int main()
{
    vector<vector<int>> grid={{2,1,1},{1,1,0},{1,1,1}};
    cout<<"time needed to rot: "<<rottingOrange(grid)<<endl;

}