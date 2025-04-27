#include <queue>
#include <climits>
#include "DijkstraAlgorithm.h"

using namespace std;

//an edge of a graph, made up of a weight and two endpoints
Edge::Edge(int new_weight, int new_endpt1, int new_endpt2)
:
weight{new_weight},
endpt1{new_endpt1},
endpt2{new_endpt2}
{
}

//computes the shortest distance between start_n and end_n given an
//adjacency matrix. returns -1 if there is no way to reach end_n from
//start_n.
int shortest_distance(vector<vector<Edge>> &adj_mat, int start_n, int end_n)
{
    int n = adj_mat.size();
    vector<int> dist(n, INT_MAX);   //tracks the minimum distance for each vertex
    vector<bool> visited(n, false); //tracks visited verticies

    dist[start_n] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_n});

    while (!pq.empty()) //until we find the minimum distance
    {
        int u = pq.top().second;
        pq.pop();

        if(!visited[u]) //don't visit u if it's already been visited
        {

            visited[u] = true;

            for (int v = 0; v < n; ++v)
            {
                if (adj_mat[u][v].weight != INT_MAX && !visited[v])
                {
                    int new_dist = dist[u] + adj_mat[u][v].weight;
                        
                    if (new_dist < dist[v])
                    {
                        dist[v] = new_dist;
                        pq.push({dist[v], v});
                    }
                }
            }
        }
    }

    return dist[end_n];     //minimum distance to end_n is stored at dist[end_n]
}
