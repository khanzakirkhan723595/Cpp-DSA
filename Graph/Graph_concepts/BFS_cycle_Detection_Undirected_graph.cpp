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
    
    bool bfsHelper(int node,vector<bool> &visited,queue<pair<int,int>> &q)
    {
        q.push({node,-1});
        visited[node]=true;
        while(q.size()>0)
        {
            int u=q.front().first;
            int par=q.front().second;
            q.pop();

            for(int neigh : Adj[u])
            {
                if(!visited[neigh])
                {
                    visited[neigh]=true;
                    q.push({neigh,u});
                }
                else if(neigh!=par)
                {
                    return true;
                }
            }
        }
        return false;

    }
    bool isCycle()
    {
        queue<pair<int,int>> q;
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                if(bfsHelper(i,visited,q))
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