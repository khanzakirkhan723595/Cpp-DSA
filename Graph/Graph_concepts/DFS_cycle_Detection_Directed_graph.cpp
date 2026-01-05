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

    // here i will use dfs
    // here we can't use backedge condition here , here we will use recPath to track path of traversal

    bool dfsHelper(int node,vector<bool> &recPath, vector<bool> &visited)
    {

        visited[node] = true;
        for (int neigh : Adj[node])
        {
            if (!visited[neigh])
            {
                if(dfsHelper(neigh,recPath,visited))
                    return true;
            }
            else if(recPath[neigh])
                return true;
        }
        recPath[node]=false;
        return false;
    }
    bool isCycle()
    {
        
        vector<bool> visited(V, false);
        vector<bool> recPath(V,false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if(dfsHelper(i,recPath, visited))
                {
                    return true;
                }
                
        }
        return false;
        
    }
};

int main()
{
    Graph g(5);
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {1, 2}, {0, 3}, {3, 4}};
    g.preAdjLst(edge);
    g.printAdjLst();
    g.calDeg();
    if(g.isCycle())
    {
        cout<<"Cycle present"<<endl;
    }
    else
        cout<<"Cycle not present"<<endl;
}