#include<bits/stdc++.h>
using namespace std;


//now write dfs algorithm
void dfs(int node,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &vis,vector<int>&ans)
{
    
    if(!vis[node])
    {
        ans.push_back(node);
    }
    vis[node]=1;
    for(auto nbr : adjList[node])
    {
        if(!vis[nbr])
        {
            vis[nbr]=1;
            ans.push_back(nbr);
            dfs(nbr,adjList,vis,ans);
        }
    }
}
vector<int> DFS(int v, vector<vector<int>> edges)
{
    //prepare adjlist
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //now start to do dfs
    unordered_map<int,bool> vis;
    vector<int>ans;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i,adjList,vis,ans);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges;
    edges.push_back({0, 4});
    edges.push_back({4, 2});
    edges.push_back({4, 1});
    edges.push_back({2, 3});
    edges.push_back({3, 5});
    edges.push_back({1, 5});
    int vertex = 6;
    vector<int> res = DFS(vertex, edges);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}

//error
/*
void dfs(int node,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &vis,vector<int>&ans)
{
    if(!vis[node])
    {
        ans.push_back(node);   // ✅ Ye sahi hai (sirf starting me node ko add karo)
    }
    vis[node]=1;

    for(auto nbr : adjList[node])
    {
        if(!vis[nbr])
        {
            vis[nbr]=1;
            ans.push_back(nbr);   // ❌ Ye galat hai (yahan dobara push kar rahe ho)
            dfs(nbr,adjList,vis,ans);
        }
    }
}
*/
//my own code is also correct but i did push_back two times
//notes=> ab aap neighbour visit karte ho, tab usse recursive call karna hi kaafi hai. ans.push_back(nbr); likhne ki zaroorat nahi hai.
//Is wajah se nodes duplicate push ho rahe the.


//complete code
/*
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &vis, vector<int> &ans)
{
    vis[node] = true;        // mark visited
    ans.push_back(node);     // add to result

    for(auto nbr : adjList[node])
    {
        if(!vis[nbr])
        {
            dfs(nbr, adjList, vis, ans);
        }
    }
}

vector<int> DFS(int v, vector<vector<int>> edges)
{
    // prepare adj list
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // now do dfs
    unordered_map<int,bool> vis;
    vector<int> ans;

    for(int i=0;i<v;i++)
    {
        if(!vis[i])
        {
            dfs(i, adjList, vis, ans);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges;
    edges.push_back({0, 4});
    edges.push_back({4, 2});
    edges.push_back({4, 1});
    edges.push_back({2, 3});
    edges.push_back({3, 5});
    edges.push_back({1, 5});

    int vertex = 6;
    vector<int> res = DFS(vertex, edges);

    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}

*/