#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> *Adj; // i am creaating it dynamically

    public:

    Graph(int V)
    {
        this->V=V;
        Adj=new vector<int> [V];
    }

    //prepare adjacency list
    void preAdjLst(vector<vector<int>> &edge)
    {
        for(int i=0;i<edge.size();i++)
        {
            int u=edge[i][0];
            int v=edge[i][1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        
    }

    //calculate degreee of each node
    void calDeg()
    {
        for(int i=0;i<V;i++)
        {
            int degree=0;
            cout<<"Degree of "<<i<<" = ";
            for(int neigh : Adj[i])
            {
                degree++;
            }
            cout<<degree<<endl;
        }
    }

    //print adjacency nodes
    void printAdjLst()
    {
        for(int u=0;u<V;u++)
        {
            cout<<u<<": ";
            for(int neigh : Adj[u])
            {
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }

    //bfs algorithm
    
    void bfsHelper(int node,vector<bool> &visited,queue<int> &q)
    {
        q.push(node);
        visited[node]=true;
        while(q.size()>0)
        {
            int u=q.front();
            q.pop();
            cout<<u<<" ";

            for(int neigh : Adj[u])
            {
                if(!visited[neigh])
                {
                    visited[neigh]=true;
                    q.push(neigh);
                }
            }
        }

    }
    void bfs()
    {
        queue<int> q;
        vector<bool> visited(V,false);
        cout<<"BFS traversal : ";
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                bfsHelper(i,visited,q);
        }
        cout<<endl;
    }
};

int main()
{
    Graph g(7);
    vector<vector<int>> edge={{0,1},{1,3},{1,2},{2,4},{5,6}};
    g.preAdjLst(edge);
    g.printAdjLst();
    g.calDeg();
    g.bfs();


}