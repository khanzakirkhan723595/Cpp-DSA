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
            //Adj[v].push_back(u);
        }
    }

    // calculate degreee of each node
    vector<int> calDeg()
    {
        vector<int> indeg(V,0);
        for (int i = 0; i < V; i++)
        {
            
            cout << "Degree of " << i << " = ";
            for (int neigh : Adj[i])
            {
                indeg[i]++;
            }
            
        }
        return indeg;
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

    void dfsTopoHelper(int node, vector<bool> &visited, vector<int> &res)
    {

        visited[node] = true;
        for (int neigh : Adj[node])
        {
            if (!visited[neigh])
            {
                dfsTopoHelper(neigh,visited,res);
            }
        }
        res.push_back(node);
    }
    void  topoSort()
    {
        
        vector<bool> visited(V, false);
        vector<int> res;
        cout << "Topological sort : ";
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfsTopoHelper(i, visited,res);
        }
        reverse(res.begin(),res.end());
        for(int i=0;i<res.size();i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Graph g(6);
    vector<vector<int>> edge = {{5,0}, {4,0}, {5,2}, {2, 3}, {3,1},{4,1}};
    g.preAdjLst(edge);
    g.printAdjLst();
    g.topoSort();
}