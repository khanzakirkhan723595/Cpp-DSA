#include <bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// #include<queue>
using namespace std;

// create adj list
void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

// bfs algorithm
void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &vis, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1;
    while (!q.empty())
    {
        int fNode = q.front();
        q.pop();
        ans.push_back(fNode);
        for (auto nbr : adjList[fNode])
        {
            if (!vis[nbr])
            {
                q.push(nbr);
                vis[nbr] = 1;
            }
        }
    }
}

// //to show on terminal
// void printBFS()
// {
//     vector<int> res=BFS(vertex,edges);
//     for(int i=0;i<BFS.size();i++)
//     {

//     }
// }

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // data structure needed
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> vis;
    prepareAdjList(adjList, edges);
    // to visit all node for dissconnected graph
    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            bfs(adjList, vis, ans, i);
        }
    }
    return ans;
}

int main()
{
    vector<pair<int, int>> edges;
    edges.push_back({0, 4});
    edges.push_back({4, 2});
    edges.push_back({4, 1});
    edges.push_back({2, 3});
    edges.push_back({3, 5});
    edges.push_back({1, 5});
    int vertex = 6;
    vector<int> res = BFS(vertex, edges);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}