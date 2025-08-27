#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Explanation of Flow:

// Input: We take n (vertices), m (edges), and all edges with weights.
// Sort Edges: Kruskal works by sorting edges by weight.
// Union-Find (DSU): Helps to detect cycles efficiently.
// findParent() → finds the ultimate parent of a node (with path compression).
// unionSet() → joins two sets (by rank optimization).
// Build MST: Pick edges one by one, if they belong to different sets → include them in MST.
// Return: Sum of all included edge weights = MST weight.

// Comparator function to sort edges by weight
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];  // compare using weight (a[2], b[2])
}

// Function to initialize Disjoint Set (DSU/Union-Find)
void makeSet(vector<int> &parent , vector<int> &rank, int n){
    for(int i=0; i<n; i++)
    {
        parent[i] = i;   // every node is its own parent initially
        rank[i] = 0;     // rank (tree height) starts from 0
    }
}

// Find function with path compression
int findParent(vector<int> &parent , int node)
{
    if(parent[node] == node)   // if node is parent of itself
    {
        return node;
    }
    // Path compression -> directly attach node to ultimate parent
    return parent[node] = findParent(parent, parent[node]);
}

// Union function (by rank)
void unionSet(int u, int v, vector<int> &parent , vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v])
    {
        parent[u] = v;   // attach smaller rank tree under bigger one
    }
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else{
        parent[v] = u;   // if equal, make one as parent
        rank[u]++;       // increase rank
    }
}

// Function to calculate MST weight using Kruskal's Algorithm
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    // Step 1: Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    // Step 2: Initialize DSU
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    // Step 3: Process edges in increasing order
    for(int i=0; i<edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]); // parent of node u
        int v = findParent(parent, edges[i][1]); // parent of node v
        int wt = edges[i][2];                    // weight of edge

        // If u and v belong to different sets, include this edge
        if(u != v)
        {
            minWeight += wt;                // add weight to MST
            unionSet(u, v, parent, rank);   // merge the sets
        }
    }
    return minWeight;  // final MST weight
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    // Each edge = {u, v, w}
    vector<vector<int>> edges(m, vector<int>(3));
    cout << "Enter edges (u v w):\n";
    for(int i=0; i<m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    // Calculate MST weight
    int ans = minimumSpanningTree(edges, n);
    cout << "Minimum Spanning Tree weight = " << ans << endl;

    return 0;
}

//input
/*
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
*/

//output
/*Minimum Spanning Tree weight = 19
*/
