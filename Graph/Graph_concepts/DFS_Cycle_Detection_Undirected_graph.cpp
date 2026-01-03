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

    // i will use dfs here to detect cycle in undirected graph and 
    // beck edge condition means if node is visited then check neighbours , if niegh is visited and equal to parent then ignore if it not equal to parent then cycle will be present;

    bool dfsHelper(int node,int par, vector<bool> &visited)
    {

        visited[node] = true;
        for (int neigh : Adj[node])
        {
            if (!visited[neigh])
            {
                if(dfsHelper(neigh,node,visited))
                    return true;
            }
            else if(neigh!=par)
                return true;
        }
        return false;
    }
    bool isCycle()
    {
        
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                if(dfsHelper(i,-1, visited))
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