#include<bits/stdc++.h>
using namespace std;


//kahn's algorithm using bfs
//it gives linear ordering of nodes where u comes before v in edges(u,v)
vector<int> topologicalSort(vector<vector<int>> &edges,int v,int e)
{
    //create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++)
    {
        int u=edges[i][0];
        int vtx=edges[i][1];  // renamed
        adj[u].push_back(vtx);
    }

    //indegree array
    vector<int> Indegree(v+1,0);  // +1 for 1-based indexing
    for(auto i : adj)
    {
        for(auto j : i.second)
        {
            Indegree[j]++;
        }
    }

    //push nodes with indegree 0
    queue<int> q;
    for(int i=1;i<=v;i++)
    {
        if(Indegree[i]==0)
            q.push(i);
    }

    //BFS
    vector<int> res;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        res.push_back(front);

        for(auto nbr : adj[front])
        {
            Indegree[nbr]--;
            if(Indegree[nbr]==0)
            {
                q.push(nbr);
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> edges;
    edges.push_back({1,2});
    edges.push_back({1,3});
    edges.push_back({2,5});
    edges.push_back({3,5});
    edges.push_back({5,4});

    int v=5, e=5;
    vector<int> ans = topologicalSort(edges,v,e);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" "; 
    }
    cout<<endl;

    return 0;
}
