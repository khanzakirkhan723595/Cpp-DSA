#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

/*
Explanation of Important Concepts:

disc[node] → Discovery time when node is first visited.

low[node] → Earliest visited vertex reachable from the subtree rooted at node.

Bridge Condition →
    An edge (u, v) is a bridge if
        low[v] > disc[u]
        This means there is no back edge from v or its descendants that can reach u or ancestors of u.
*/

// Depth-First Search (DFS) function to detect bridges
void dfs(int node, int parent, int &timer,
         vector<int> &disc, vector<int> &low,
         vector<vector<int>> &result,
         unordered_map<int,list<int>> &adj,
         unordered_map<int,bool> &vis)
{
    vis[node] = true;              // mark current node visited
    disc[node] = low[node] = timer++;  // discovery time and low value

    // Explore all neighbors
    for(auto nbr: adj[node])
    {
        if(nbr == parent) // skip edge leading back to parent
            continue;

        if(!vis[nbr]) // if neighbor not visited → DFS
        {
            dfs(nbr, node, timer, disc, low, result, adj, vis);

            // After DFS, update low[node] based on neighbor
            low[node] = min(low[node], low[nbr]);

            // Check bridge condition
            if(low[nbr] > disc[node]) 
            {
                // Edge (node - nbr) is a bridge
                result.push_back({node, nbr});
            }
        }
        else
        {
            // Back edge found → update low[node]
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

// Function to find all bridges in a graph
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Step 1: Create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: Initialize helper arrays
    int timer = 0;
    vector<int> disc(v, -1);   // discovery time of each node
    vector<int> low(v, -1);    // lowest discovery time reachable
    unordered_map<int,bool> vis;  // visited array
    vector<vector<int>> result;   // to store bridges

    // Step 3: Run DFS for all components
    for(int i=0; i<v; i++)
    {
        if(!vis[i])
        {
            dfs(i, -1, timer, disc, low, result, adj, vis);
        }
    }

    return result;
}

// Driver code
int main()
{
    int v, e;
    cout << "Enter number of vertices and edges: ";
    cin >> v >> e;

    vector<vector<int>> edges;
    cout << "Enter edges (u v):" << endl;
    for(int i=0; i<e; i++)
    {
        int u, vtx;
        cin >> u >> vtx;
        edges.push_back({u, vtx});
    }

    // Find bridges
    vector<vector<int>> bridges = findBridges(edges, v, e);

    // Print result
    cout << "\nBridges in the graph are:\n";
    for(auto bridge: bridges)
    {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}


//input
/*
Enter number of vertices and edges: 5 5
Enter edges (u v):
0 1
1 2
2 0
1 3
3 4
*/

//output
/*
Bridges in the graph are:
3 - 4
1 - 3
*/
