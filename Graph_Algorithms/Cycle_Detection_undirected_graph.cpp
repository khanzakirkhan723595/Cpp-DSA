#include<bits/stdc++.h>
using namespace std;


//condition for graph present
//if neighbour is visted and neighbour is not equal to parent 

//---------------- BFS Approach ----------------//

// Function to check cycle in an undirected graph using BFS
bool isCycleBFS(int src, unordered_map<int,bool> &vis, unordered_map<int,vector<int>> &adj)
{
    unordered_map<int,int> parent;   // to track parent of each node
    queue<int> q;

    vis[src] = 1;          // mark source as visited
    parent[src] = -1;      // source has no parent
    q.push(src);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        // Traverse all neighbors of current node
        for(auto nbr : adj[front])
        {
            // If neighbor already visited and not parent → cycle found
            if(vis[nbr] == true && nbr != parent[front])
            {
                return true;
            }
            // If neighbor not visited → visit it
            else if(!vis[nbr])
            {
                vis[nbr] = 1;
                q.push(nbr);
                parent[nbr] = front;   // store parent for backtracking
            }
        }
    }
    return false;   // No cycle found
}

// Wrapper function for BFS cycle detection
string cycleDetection1(vector<vector<int>> &edges, int n)
{
    // Step 1: Build adjacency list
    unordered_map<int,vector<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);   // because undirected graph
    }

    // Step 2: Traverse each component (in case graph is disconnected)
    unordered_map<int,bool> vis;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            bool ans = isCycleBFS(i, vis, adj);
            if(ans == 1)
                return "Cycle is present";
        }
    }
    return "No cycle";
}

//---------------- DFS Approach ----------------//

// Function to check cycle using DFS
bool isCycleDFS(int node, int parent, unordered_map<int,bool> &vis, unordered_map<int,vector<int>> &adj)
{
    vis[node] = 1;   // mark node as visited

    // Traverse all neighbors
    for(auto nbr : adj[node])
    {
        if(!vis[nbr])
        {
            // DFS recursive call
            bool cycleDetected = isCycleDFS(nbr, node, vis, adj);
            if(cycleDetected)
                return true;
        }
        // If neighbor is visited and not parent → cycle found
        else if(vis[nbr] == true && nbr != parent)
        {
            return true;
        }
    }
    return false;   // No cycle found
}

// Wrapper function for DFS cycle detection
string cycleDetection2(vector<vector<int>> &edges, int n)
{
    // Step 1: Build adjacency list
    unordered_map<int,vector<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);   // because undirected graph
    }

    // Step 2: Traverse each component
    unordered_map<int,bool> vis;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            bool ans = isCycleDFS(i, -1, vis, adj);
            if(ans == 1)
                return "Cycle is present";
        }
    }
    return "No cycle";
}

//---------------- Main Function ----------------//
int main()
{
    // Example graph edges
    vector<vector<int>> edges;
    edges.push_back({0, 4});
    edges.push_back({4, 2});
    edges.push_back({4, 1});
    edges.push_back({2, 3});
    edges.push_back({3, 5});
    edges.push_back({1, 5});

    int n = 6; // number of nodes (0 to 5)

    // Run DFS based cycle detection
    cout << cycleDetection2(edges, n) << endl;

    return 0;
}
