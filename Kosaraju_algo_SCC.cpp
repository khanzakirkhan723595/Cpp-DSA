#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

/*
Explanation of Kosaraju’s Algorithm:

DFS + Stack (Topo Order) → Perform DFS on original graph and push nodes into a stack when DFS finishes.
Transpose Graph → Reverse the direction of all edges.
DFS on Transposed Graph → Process nodes in stack order. Each DFS call = 1 Strongly Connected Component.*/

// Step 1: Perform DFS and store nodes in stack (Topological Sort order)
void dfs(int node, unordered_map<int,bool> &vis, stack<int> &st, unordered_map<int,list<int>> &adj) {
    vis[node] = true;

    // Visit all neighbours
    for(auto nbr: adj[node]) {
        if(!vis[nbr]) {
            dfs(nbr, vis, st, adj);
        }
    }

    // Once DFS finishes for a node, push into stack
    st.push(node);
}

// Step 2: DFS for the Transposed Graph
void revDfs(int node, unordered_map<int,bool> &vis, unordered_map<int,list<int>> &transpose) {
    vis[node] = true;

    // Visit all neighbours in the transposed graph
    for(auto nbr: transpose[node]) {
        if(!vis[nbr]) {
            revDfs(nbr, vis, transpose);
        }
    }
}

// Function to find Strongly Connected Components (Kosaraju’s Algorithm)
int stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    // ------------------ Step 1: Create adjacency list ------------------
    unordered_map<int,list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);  // Directed edge u → v
    }

    // ------------------ Step 2: Topological Sort using DFS ------------------
    stack<int> st; 
    unordered_map<int,bool> vis;

    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    // ------------------ Step 3: Create Transpose Graph ------------------
    unordered_map<int,list<int>> transpose;
    for(int i=0; i<v; i++) {
        vis[i] = false;  // Reset visited array for 2nd DFS
        for(auto nbr: adj[i]) {
            transpose[nbr].push_back(i); // Reverse edge
        }
    }

    // ------------------ Step 4: DFS on Transposed Graph ------------------
    int count = 0; // Number of SCCs
    while(!st.empty()) {
        int top = st.top();
        st.pop();

        if(!vis[top]) {
            // Each DFS call in transpose = 1 SCC
            count++;
            revDfs(top, vis, transpose);
        }
    }

    return count;
}

// ------------------ Driver Code ------------------
int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter edges (u v) directed:" << endl;
    for(int i=0; i<e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    int result = stronglyConnectedComponents(v, edges);
    cout << "Number of Strongly Connected Components: " << result << endl;

    return 0;
}

//inputs
/*
Enter number of vertices: 5
Enter number of edges: 5
Enter edges (u v) directed:
0 1
1 2
2 0
1 3
3 4
*/

//output
//Number of Strongly Connected Components: 3

