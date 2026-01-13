#include <bits/stdc++.h>
using namespace std;

// applicable for directed graph
// weight can be positive or negative
//  can also detect negative cycle
//it is inplace algorithm

void floydWarshall(vector<vector<int>> &dist)
{
    
    int n = dist.size();

    //if INT_MAX is not present then convert it to int_max and at the end replace with int_max
    // Convert 100000000 to INT_MAX

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == 100000000)
            {
                dist[i][j] = INT_MAX;
            }
        }
    }

    // floyd worshall:
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                // INT_MAX + INT_MAX = overflow
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    //// Optional: convert INT_MAX back to 100000000

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INT_MAX)
            {
                dist[i][j] = 100000000;
            }
        }
    }
}

int main()
{
    vector<vector<int>> dist = {{0, 4, 100000000, 5, 100000000}, {100000000, 0, 1, 100000000, 6}, {2, 100000000, 0, 3, 100000000}, {100000000, 100000000, 1, 0, 2}, {1, 100000000, 100000000, 4, 0}};
    int n=dist.size();
    floydWarshall(dist);

    for (int i = 0; i < n; i++)
        {
            cout<<"[ ";
            for (int j = 0; j < n; j++)
            {

                cout<<dist[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }

}