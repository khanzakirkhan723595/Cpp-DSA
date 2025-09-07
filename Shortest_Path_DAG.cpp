#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

/*class DAG{
    public:
        unordered_map<int,list<pair<int,int>>> adj;

        void addEdge(int u,int v,int weight)
        {
            pair<int,int> p =make_pair(v,weight);
            adj[u].push_back(p);

        }

        void printAdj(){
            for(auto i:adj)
            {
                cout<<i.first<<" -> ";
                for(auto j:i.second){
                    cout<<"{"<<j.first<<","<<j.second<<"}, ";
                }
                cout<<endl;
            }
        }

        void dfs(int node , unordered_map<int,bool> &vis,stack<int> &topo)
        {
            vis[node]=true;
            for(auto neighbour : adj[node]){
                if(!vis[neighbour.first]){
                    dfs(neighbour.first,vis,topo);
                }

            }
            topo.push(node);


        }

        void getShortestPath(int src,vector<int> &dist , stack<int> &topo)
        {
            dist[src]=0;

            while(!topo.empty()){
                int top=topo.top();
                topo.pop();

                if(dist[top]!=INT_MAX)
                {
                    for(auto i: adj[top]){
                        if(dist[top] + i.second < dist[i.first])
                        {
                            dist[i.first]=dist[top] + i.second ;
                        }
                    }
                }
            }
        }


};

int main()
{
    DAG g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();

    int n=6;
    //topological sort
    unordered_map<int , bool> visited;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            g.dfs(i,visited,s);
        }
    }

    int src=1;
    vector<int> dist(n);
    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;

    }
    g.getShortestPath(src,dist,s);

    cout<<"Answer is: "<<endl;

    for(int i=0;i<dist.size();i++)
    {
        cout<<dist[i]<<" ";
    }cout<<endl;


    return 0;
}*/


#include <bits/stdc++.h>
using namespace std;

class ShortestDAG {
public:
    // adjacency list: node -> list of {neighbor, weight}
    unordered_map<int, vector<pair<int,int>>> adj;

    // Build adjacency list from edge list
    void createAdjList(vector<vector<int>> &edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
    }

    // DFS for topological sorting
    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &topo) {
        vis[node] = true;
        for (auto nbr : adj[node]) {
            if (!vis[nbr.first]) {
                dfs(nbr.first, vis, topo);
            }
        }
        topo.push(node); // push after visiting all neighbors
    }

    // Get shortest path using Topological order
    vector<int> getShortestPath(int src, int n) {
        // Step 1: Topological Sort
        unordered_map<int, bool> vis;
        stack<int> topo;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, topo);
            }
        }

        // Step 2: Initialize distances
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Step 3: Process nodes in topo order
        while (!topo.empty()) {
            int node = topo.top();
            topo.pop();

            if (dist[node] != INT_MAX) {
                for (auto nbr : adj[node]) {
                    int v = nbr.first;
                    int wt = nbr.second;

                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        return dist;
    }
};

int main() {
    // Graph edges: {u, v, w}
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {4, 5, 4},
        {2, 3, 6},
        {5, 3, 1}
    };

    int n = 6; // total nodes (0 to 5)
    int src = 0;

    ShortestDAG g;
    g.createAdjList(edges);

    vector<int> dist = g.getShortestPath(src, n);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) cout << i << " -> INF\n";
        else cout << i << " -> " << dist[i] << "\n";
    }

    return 0;
}
