#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<list>
using namespace std;

/*
    DFS function to find articulation points in a graph.
    Parameters:
    - node   : current node being visited
    - parent : parent of the current node in DFS tree
    - disc   : discovery time of each node
    - low    : lowest discovery time reachable from the subtree
    - vis    : visited map
    - adj    : adjacency list
    - ap     : stores articulation points (1 if AP, else 0)
    - timer  : global timer for discovery times
*/
void dfs(int node, int parent, vector<int> &disc, vector<int> &low,
         unordered_map<int,bool> &vis, unordered_map<int,list<int>> &adj,
         vector<int> &ap, int &timer)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;  // assign discovery & low time
    int child = 0; // count children (important for root case)

    // Traverse all neighbours
    for(auto nbr : adj[node])
    {
        if(nbr == parent) continue; // skip edge to parent

        if(!vis[nbr])  // if neighbour is not visited
        {
            dfs(nbr, node, disc, low, vis, adj, ap, timer);

            // update low value of current node
            low[node] = min(low[node], low[nbr]);

            // AP condition (excluding root)
            if(low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1; // mark node as articulation point
            }

            child++; // increase child count
        }
        else
        {
            // back edge found → update low value
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // Special case: if root and has more than 1 child → AP
    if(parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main()
{
    // Number of vertices and edges
    int n = 5;
    int e = 5;

    // Edges of the graph
    vector<pair<int,int>> edges;
    edges.push_back({0,3});
    edges.push_back({3,4});
    edges.push_back({0,4});
    edges.push_back({0,1});
    edges.push_back({1,2});

    // Build adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize variables
    int timer = 0;
    vector<int> disc(n, -1);  // discovery time
    vector<int> low(n, -1);   // low time
    unordered_map<int,bool> vis; // visited map
    vector<int> ap(n, 0);     // articulation point marker

    // Run DFS for each component
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i, -1, disc, low, vis, adj, ap, timer);
        }
    }

    // Print articulation points
    cout << "Articulation points are: ";
    for(int i=0; i<n; i++)
    {
        if(ap[i] != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}

/*
Explanation of Key Parts

Discovery Time (disc[]) → When a node is first visited.
Low Time (low[]) → The earliest discovered node reachable from this node (using back edges).
Articulation Point Conditions:
If parent == -1 (root of DFS) and it has more than 1 child → AP.
If parent != -1 and for a neighbour nbr, low[nbr] >= disc[node] → AP.
Back Edge Handling → If a neighbour is already visited and not parent, update low[node].
*/
