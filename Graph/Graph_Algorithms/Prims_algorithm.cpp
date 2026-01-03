#include<iostream>
#include<unordered_map>
#include<list>
#include<limits.h>
#include<vector>
using namespace std;

// Flow of Algorithm:

// Build adjacency list from input edges.
// Initialize arrays:
// key[] → stores min edge weight needed to connect a node to MST.
// mst[] → keeps track of nodes already in MST.
// parent[] → stores parent node in MST tree.
// Pick smallest key node not yet in MST.
// Update its neighbors with smaller edge weights.
// Repeat until MST has n-1 edges.
// Return edges and total weight of MST.



// Function to calculate MST using Prim's Algorithm
vector<pair<pair<int,int>,int>> calculatePrimsMST(int n, int m, vector<pair<pair<int,int>,int>> &g){

    // Step 1: Create adjacency list from given edge list
    // adj[u] = list of {v, weight} where u-v is an edge
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        // Since it's an undirected graph, add both u->v and v->u
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Step 2: Initialize helper arrays
    vector<int> key(n+1, INT_MAX);   // key[i] = minimum weight edge to include vertex i in MST
    vector<bool> mst(n+1, false);    // mst[i] = true if vertex i is already in MST
    vector<int> parent(n+1, -1);     // parent[i] = parent of i in MST

    // Step 3: Start Prim's algorithm from node 1
    key[1] = 0;        // Start node (1) has key value = 0 (so it gets picked first)
    parent[1] = -1;    // Root node has no parent

    // Step 4: Repeat for (n-1) edges (MST always has n-1 edges)
    for(int i=1; i<n; i++)
    {
        int mini = INT_MAX;
        int u;

        // Step 4.1: Pick the minimum key node which is not yet in MST
        for(int v=1; v<=n; v++)
        {
            if(mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // Step 4.2: Include this node in MST
        mst[u] = true;

        // Step 4.3: Update adjacent vertices
        for(auto it: adj[u])
        {
            int v = it.first;
            int w = it.second;

            // If v is not yet in MST and weight(u-v) < key[v], update
            if(mst[v] == false && w < key[v])
            {
                parent[v] = u;   // parent of v is u
                key[v] = w;      // update minimum edge weight
            }
        }
    }

    // Step 5: Store result MST edges
    vector<pair<pair<int,int>,int>> result;
    for(int i=2; i<=n; i++) // start from 2 because node 1 has no parent
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main()
{
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // Input graph edges: (u, v, w)
    vector<pair<pair<int,int>,int>> g;
    cout << "Enter edges (u v w):" << endl;
    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({{u, v}, w});
    }

    // Run Prim’s algorithm
    vector<pair<pair<int,int>,int>> mst = calculatePrimsMST(n, m, g);

    // Output MST edges
    cout << "\nMST edges are:" << endl;
    int totalWeight = 0;
    for(auto edge: mst)
    {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
        totalWeight += edge.second;
    }
    cout << "Total weight of MST = " << totalWeight << endl;

    return 0;
}


//example
/*
5 6
1 2 2
1 4 6
2 3 3
2 4 8
3 5 7
4 5 9
*/

//output
/*
MST edges are:
1 - 2 : 2
2 - 3 : 3
1 - 4 : 6
3 - 5 : 7
Total weight of MST = 18
*/
