#include<iostream>
#include<unordered_map>
#include<set>
#include<limits.h>
#include<list>
#include<vector>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec ,int vertices,int edges,int source){
    // Step 1: Create adjacency list
    // adj[u] = list of {v, w} meaning edge u-v with weight w
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back({v, w});   // u -> v
        adj[v].push_back({u, w});   // v -> u (undirected graph)
    }

    // Step 2: Initialize distance array
    vector<int> dist(vertices, INT_MAX);  // dist[i] = shortest distance from source to i

    // Step 3: Use set (acts like a min-priority queue)
    // set stores pairs of {distance, node}
    set<pair<int,int>> st;

    // Step 4: Distance to source node = 0
    dist[source] = 0;
    st.insert({0, source});  // {distance, node}

    // Step 5: Process the set until it becomes empty
    while(!st.empty())
    {
        // Fetch the node with smallest distance
        auto top = *(st.begin()); // first element in set = minimum
        int nodeDistance = top.first;
        int topNode = top.second;

        // Remove this node from set
        st.erase(st.begin());

        // Step 6: Traverse neighbors of current node
        for(auto neighbour : adj[topNode])
        {
            int adjNode = neighbour.first;
            int edgeWeight = neighbour.second;

            // Relaxation step
            if(nodeDistance + edgeWeight < dist[adjNode]){

                // If record for adjNode already exists in set, remove it
                auto record = st.find({dist[adjNode], adjNode});
                if(record != st.end())
                {
                    st.erase(record);
                }

                // Update distance
                dist[adjNode] = nodeDistance + edgeWeight;

                // Insert new pair in set
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist; // return shortest distance to all vertices
}

int main()
{
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    vector<vector<int>> vec(edges, vector<int>(3));
    cout << "Enter edges (u v w):" << endl;
    for(int i=0; i<edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vec[i][0] = u;
        vec[i][1] = v;
        vec[i][2] = w;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    // Run Dijkstra
    vector<int> res = dijkstra(vec, vertices, edges, source);

    // Print shortest distances
    cout << "\nShortest distances from source " << source << ":\n";
    for(int i=0; i<res.size(); i++)
    {
        cout << "Node " << i << " -> Distance = " << res[i] << endl;
    }

    return 0;
}

//input
/*
Enter number of vertices and edges: 5 7
Enter edges (u v w):
0 1 7
0 2 1
0 3 2
1 2 3
1 3 5
1 4 1
3 4 7
Enter source vertex: 0
*/

//output
/*
Shortest distances from source 0:
Node 0 -> Distance = 0
Node 1 -> Distance = 5
Node 2 -> Distance = 1
Node 3 -> Distance = 2
Node 4 -> Distance = 6
*/