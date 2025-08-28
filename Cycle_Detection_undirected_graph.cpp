#include<bits/stdc++.h>
using namespace std;

//using BFS algorithm
bool isCycleBFS(int src,unordered_map<int,bool> &vis,unordered_map<int,vector<int>> &adj)
{
    unordered_map<int,int> parent;
    queue<int> q;
    vis[src]=1;
    parent[src]=-1;
    q.push(src);
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto nbr : adj[front])
        {
            if(vis[nbr]==true && nbr!=parent[front])
            {
                return true;
            }
            else if(!vis[nbr])
            {
                vis[nbr]=1;
                q.push(nbr);
                parent[nbr]=front;
            }
        }
    }
    return false;

}

string cycleDetection(vector<vector<int>> &edges,int n)
{
    //prepare adjList 
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //use for loop to traverese for loop
    unordered_map<int,bool> vis;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            bool ans=isCycleBFS(i,vis,adj);
            if(ans==1)
                return "cycle is present";
        }

    }
    return "No cylce ";
}



//using DFS 


int main()
{
    vector<vector<int>> edges;
    edges.push_back({0, 4});
    edges.push_back({4, 2});
    edges.push_back({4, 1});
    edges.push_back({2, 3});
    edges.push_back({3, 5});
    edges.push_back({1, 5});

    int n= 6;
    cout<<cycleDetection(edges,n)<<endl;

    return 0;
}