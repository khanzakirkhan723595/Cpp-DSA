#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> prepareAdj(int V,vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    return adj;

}

vector<int> TopoBfs(int V,vector<vector<int>> &edges)
{
    vector<int> indeg(V,0);
    vector<vector<int>> Adj=prepareAdj(V,edges);
    for(int i=0;i<V;i++)
    {
        for(int v:Adj[i])
        {
            //If there is an edge u → v, then v's indegree increases, not u’s.
            indeg[v]++;
        }
    }

    //push zero indegree vertex in queue
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    vector<int> res;
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        res.push_back(curr);
        for(int n : Adj[curr])
        {
            indeg[n]--;
            if(indeg[n]==0)
            {
                q.push(n);
            }
        }
    }
    return res;

}

int main()
{
    int V=6;
    vector<vector<int>> edge = {{5,0}, {4,0}, {5,2}, {2, 3}, {3,1},{4,1}};
    cout<<"TOPO bfs: ";
    vector<int> ans=TopoBfs(V,edge);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}
