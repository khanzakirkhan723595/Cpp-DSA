#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> preAdjLst(vector<vector<int>> &edges, int V)
{
    vector<vector<pair<int, int>>> Adj(V);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        Adj[u].push_back({v, w});
        // Adj[v].push_back(u);
    }
    return Adj;
}
// dijkstraa's  algorithm
vector<int> shortestDist(vector<vector<int>> &edges, int V)
{
    vector<vector<pair<int, int>>> adj = preAdjLst(edges, V);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    pq.push({0, 0});
    while (pq.size() > 0)
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for (pair<int, int> p : adj[u])
        {
            int v = p.first;
            int uvw = p.second;
            if (dist[v] > dist[u] + uvw)
            {
                dist[v] = dist[u] + uvw;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{

    vector<vector<int>> edge = {{0, 1, 2}, {1, 3, 7}, {3, 5, 1}, {4, 5, 5}, {4, 3, 2}, {2, 4, 3}, {1, 2, 1}, {0, 2, 4}};
    int V = 6;
    vector<int> res = shortestDist(edge, V);
    for (int i = 0; i < V; i++)
    {
        cout << "Distance from '0' -> " << i << " : " << res[i] << endl;
    }
    return 0;
}