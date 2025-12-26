#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<int> *adj; //int *arr;
    //we can use list also it is better because it is doubly linked list , here we can push_back or push_front, pop, size , two pointer like front and back also 
    //list<int> *l;

    public:
    Graph(int V)
    {
        this->V=V;
        adj=new vector<int> [V]; //arr=new int[V]
        //l=new list<int> [V];

    }
    void prepareAdjLst(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    /*void printVertices()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<" : ";
            for(int neigh : adj[i])
            {
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }*/
   void bfs()
   {
        queue<int> q;
        vector<int> vis(V,false);
        q.push(0);
        vis[0]=true;
        while(q.size()>0)
        {
            int u = q.front();
            q.pop();

            cout<<u<<" ";
            for(int neigh : adj[u])
            {
                if(!vis[neigh])
                {
                    vis[neigh]=true;
                    q.push(neigh);
                }
            }

        }
        cout<<endl;
   }

   void dfsHelper(int u,vector<bool> &vis)
   {
        cout<<u<<" ";
        vis[u]=true;
        for(int v : adj[u])
        {
            if(!vis[v])
            {
                dfsHelper(v,vis);
            }
        }
    
   }
   void dfs()
   {
        int src=0;
        vector<bool> vis(V,false);
        dfsHelper(src,vis);
        cout<<endl;
   }


   bool iscycleUndirDfs(int src, int parent,vector<bool> &vis)
   {
        vis[src]=true;
        for(int v : adj[src])
        {
            if(!vis[v])
            {
                //Agar DFS ke kisi bhi level pe cycle mil jaaye, to hum poore recursion chain ko true bhej dete hain.
                /*
                iscyclehelper(0)
                 └── iscyclehelper(1)
                      └── iscyclehelper(2)
                           └── iscyclehelper(3)  ← cycle found
                                return true
                           return true
                      return true
                 return true

                */
                if(iscycleUndirDfs(v,src,vis))
                {
                    return true;
                }
            }
            else if(v!=parent)
            {
                return true;
            }
        }
        return false;
   }

   bool iscycle(){
   
        vector<bool> vis(V, false);
        for(int u=0;u<V;u++)
        {
            if(!vis[u])
            {
                if(iscycleUndirDfs(u,-1,vis))
                {
                    return true;
                }
            }
            
        }
        return false;
   }

   bool iscycleBfsHelper(int src,vector<bool>&vis)
   {
        queue<pair<int,int>>q;
        vis[src]=true;
        q.push({src,-1});
        while(q.size()>0)
        {
            int u=q.front().first;
            int parU=q.front().second;
            for(int v : adj[u])
            {
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push({v,u});
                }
                else if(v!=parU)
                {
                    return true;
                }
            }
        }
        return false;


   }
   bool iscycleBfs()
   {

        vector<bool>vis(V,false);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(iscycleBfsHelper(i,vis))
                {
                    return true;
                }
            }
        }
        return false;

   }

};
int main()
{
    Graph g(5);
    g.prepareAdjLst(0,1);
    g.prepareAdjLst(0,2);
    g.prepareAdjLst(0,3);
    g.prepareAdjLst(1,2);
    g.prepareAdjLst(3,4);

    //g.printVertices();
    cout<<"bfs traversal : ";
    g.bfs();
    cout<<"dfs traversal : ";
    g.dfs();

    //cycle detect using dfs
    cout<<"cycle detect using dfs"<<endl;
    if(g.iscycle())
    {
        cout<<"Cycle Present "<<endl;
    }
    if(!g.iscycle())
    {
        cout<<"Cycle not Present "<<endl;
    }

    //cycle detect using bfs
    cout<<"cycle detect using bfs"<<endl;
    if(g.iscycleBfs())
    {
        cout<<"Cycle Present "<<endl;
    }
    if(!g.iscycleBfs())
    {
        cout<<"Cycle not Present "<<endl;
    }

    
    



}


