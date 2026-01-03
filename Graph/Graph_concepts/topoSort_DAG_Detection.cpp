#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& state, vector<int>& order)
    {
        state[node] = 1;   // visiting

        for(int v : adj[node])
        {
            if(state[v] == 0)
            {
                if(dfs(v, adj, state, order))
                    return true;   // cycle found
            }
            else if(state[v] == 1)
            {
                return true;      // back edge → cycle
            }
        }

        state[node] = 2;           // visited
        order.push_back(node);     // topo step
        return false;
    }

    vector<int> findOrder(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);
        for(auto &e : edges)
            adj[e[1]].push_back(e[0]);

        vector<int> state(V, 0);
        vector<int> order;

        for(int i = 0; i < V; i++)
        {
            if(state[i] == 0)
            {
                if(dfs(i, adj, state, order))
                    return {};   // cycle exists
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};

int main()
{
    Solution s;
    int V;
    vector<vector<int>> edges=
    s.findOrder()
}