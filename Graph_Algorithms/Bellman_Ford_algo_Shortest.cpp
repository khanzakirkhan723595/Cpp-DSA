#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

// Function to implement Bellman-Ford Algorithm
// n -> number of vertices
// m -> number of edges
// src -> source node
// dest -> destination node
// edges -> edge list (u, v, weight)
int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Step 1: Initialize distance array with "infinity"
    // We use 1e9 as infinity representation
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;  // Distance to source is always 0

    // Step 2: Relax all edges (n-1) times
    // Why (n-1)? Because the longest path in a graph without a cycle
    // has at most (n-1) edges
    for (int i = 1; i <= n - 1; i++)
    {
        // Traverse each edge
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0]; // start node
            int v = edges[j][1]; // end node
            int wt = edges[j][2]; // edge weight

            // If the source vertex is reachable
            // and going via u gives a shorter distance to v, relax it
            if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Step 3: Check for negative weight cycle
    // Run one more relaxation to see if distance reduces further
    bool hasNegativeCycle = false;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
        {
            hasNegativeCycle = true;
        }
    }

    // If no negative cycle, return shortest distance to destination
    if (!hasNegativeCycle)
    {
        return dist[dest];
    }

    // If negative cycle exists, return -1
    return -1;
}

// Driver code
int main()
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges;

    cout << "Enter edges (u v wt):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int src, dest;
    cout << "Enter source and destination: ";
    cin >> src >> dest;

    int result = bellmanFord(n, m, src, dest, edges);

    if (result == -1)
    {
        cout << "Graph contains a negative weight cycle." << endl;
    }
    else
    {
        cout << "Shortest distance from " << src << " to " << dest << " is: " << result << endl;
    }

    return 0;
}

//input
/*
Enter number of vertices and edges: 5 7
Enter edges (u v wt):
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
Enter source and destination: 0 4
*/

//output
//Shortest distance from 0 to 4 is: 1

