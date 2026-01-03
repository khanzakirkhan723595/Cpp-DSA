#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *Adj; // i am creaating it dynamically

public:
    Graph(int V)
    {
        this->V = V;
        Adj = new vector<int>[V];
    }

    // prepare adjacency list
    void preAdjLst(vector<vector<int>> &edge)
    {
        for (int i = 0; i < edge.size(); i++)
        {
            int u = edge[i][0];
            int v = edge[i][1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
    }

    // calculate degreee of each node
    void calDeg()
    {
        for (int i = 0; i < V; i++)
        {
            int degree = 0;
            cout << "Degree of " << i << " = ";
            for (int neigh : Adj[i])
            {
                degree++;
            }
            cout << degree << endl;
        }
    }

    // print adjacency nodes
    void printAdjLst()
    {
        for (int u = 0; u < V; u++)
        {
            cout << u << ": ";
            for (int neigh : Adj[u])
            {
                cout << neigh << " ";
            }
            cout << endl;
        }
    }

    // dfs algorithm

    void dfsHelper(int node, vector<bool> &visited)
    {

        visited[node] = true;
        cout<<node<<" ";
        for (int neigh : Adj[node])
        {
            if (!visited[neigh])
            {
                dfsHelper(neigh,visited);
            }
        }
    }
    void dfs()
    {
        
        vector<bool> visited(V, false);
        cout << "DFS traversal : ";
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfsHelper(i, visited);
        }
        cout << endl;
    }
};

int main()
{
    Graph g(7);
    vector<vector<int>> edge = {{0, 1}, {1, 3}, {1, 2}, {2, 4}, {5, 6}};
    g.preAdjLst(edge);
    g.printAdjLst();
    g.calDeg();
    g.dfs();
}