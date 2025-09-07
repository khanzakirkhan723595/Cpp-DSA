#include <bits/stdc++.h>
using namespace std;

vector<int> ShortestPath(vector<pair<int,int>> edges, int n, int m, int s, int d)
{
    // Step 1: Create adjacency list
    unordered_map<int, vector<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: BFS Traversal
    unordered_map<int,bool> vis;
    unordered_map<int,int> parent;
    queue<int> q;

    vis[s] = true;
    parent[s] = -1;
    q.push(s);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto nbr: adj[front])
        {
            if(!vis[nbr])
            {
                vis[nbr] = true;
                parent[nbr] = front;
                q.push(nbr);

                if(nbr == d) break; // early exit
            }
        }
    }

    // Step 3: Reconstruct path from destination → source
    vector<int> ans;
    int currNode = d;
    ans.push_back(d);

    while(currNode != s)
    {
        currNode = parent[currNode]; 
        ans.push_back(currNode);
    }

    // Step 4: Reverse the path
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<pair<int,int>> edges = {
        {1,2},{2,5},{5,8},{1,3},{3,8},{1,4},{4,6},{6,7},{7,8}
    };
    
    int n=8, m=9, s=1, d=8;
    vector<int> res = ShortestPath(edges, n, m, s, d);

    cout << "Shortest Path from " << s << " to " << d << ": ";
    for(int i=0;i<res.size();i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}
