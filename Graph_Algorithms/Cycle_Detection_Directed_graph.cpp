#include<bits/stdc++.h>
using namespace std;

// METHOD 1 USING  VIS AND DFSVIS ARRAY AND DFS ALGORITHM



// Helper function: DFS traversal
// ------------------------------
// This function checks if there is a cycle starting from 'node'
// vis[node]   → marks whether the node has ever been visited
// dfsvis[node]→ marks whether the node is currently in recursion stack
// adj         → adjacency list of directed graph
bool isCycleDFS(int node, unordered_map<int,bool> &vis, unordered_map<int,bool> &dfsvis, unordered_map<int,vector<int>> &adj)
{
    vis[node] = true;      // mark node as visited
    dfsvis[node] = true;   // mark node as part of current recursion stack

    // traverse all neighbours of current node
    for(auto nbr : adj[node])
    {
        // case 1: if neighbour is not visited → recurse
        if(!vis[nbr])
        {
            bool cycledetect = isCycleDFS(nbr, vis, dfsvis, adj);
            if(cycledetect) 
                return true;  // cycle found deeper
        }
        // case 2: if neighbour is visited & also in recursion stack
        else if(dfsvis[nbr] == true)
        {
            return true;  // cycle detected
        }
    }

    // backtracking step: remove node from recursion stack
    dfsvis[node] = false;
    return false;
}

// -------------------------------------------
// Main cycle detection function for all nodes
// -------------------------------------------
int detectCycleDG(int n, vector<pair<int,int>> &edges)
{
    // Step 1: Build adjacency list for directed graph
    unordered_map<int,vector<int>> adj;
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);  // directed edge u → v
    }

    // Step 2: Define visited and recursion-stack maps
    unordered_map<int,bool> vis;
    unordered_map<int,bool> dfsvis;

    // Step 3: Check cycle for every unvisited node
    for(int i=1; i<=n; i++)   // (1-based indexing assumed)
    {
        if(!vis[i])
        {
            bool detectcycle = isCycleDFS(i, vis, dfsvis, adj);
            if(detectcycle) 
                return true;  // cycle found
        }
    }
    return false;  // no cycle
}

// METHOD 2 USING TOPOLOGICAL SORT
//if(count==n) returrn false; means no cycle is there i.e., acyclic graph ,else return true means cycle present

string topologicalSort(vector<vector<int>> &edges,int v,int e)
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
    int count=0; //vector<int> res;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        count++; //res.push_back(front);

        for(auto nbr : adj[front])
        {
            Indegree[nbr]--;
            if(Indegree[nbr]==0)
            {
                count++; //q.push(nbr);
            }
        }
    }
    if(count==v)
        return "cycle not present";
    else 
        return "cycle present";

}



















// Driver function
// for dfs
/*int main()
{
    // Example graph edges (directed graph)
    vector<pair<int,int>> edges;
    edges.push_back({1,2});
    edges.push_back({2,4});
    edges.push_back({4,3});
    edges.push_back({3,2});   // this back edge creates a cycle (2→4→3→2)
    edges.push_back({1,3});

    int n = 4; // number of nodes

    int res = detectCycleDG(n, edges);
    if(res == 1)
        cout << "Cycle Present" << endl;
    else
        cout << "Not Present" << endl;

    return 0;
}*/


//for topological sort
int main()
{
    vector<vector<int>> edges;
    edges.push_back({1,2});
    edges.push_back({2,4});
    edges.push_back({4,3});
    edges.push_back({3,2});   // this back edge creates a cycle (2→4→3→2)
    edges.push_back({1,3});

    int n = 4; // number of nodes
    int e=5;
    cout<<topologicalSort(edges,n,e)<<endl;
    return 0;

}
