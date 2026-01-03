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
};

int main()
{
    Graph g(5);
    vector<vector<int>> edge={{0,1},{1,3},{1,2},{2,4}};
    g.preAdjLst(edge);
    g.printAdjLst();
    g.calDeg();


}