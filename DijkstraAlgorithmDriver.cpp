#include <iostream>
#include <climits>
#include "DijkstraAlgorithm.h"

using namespace std;

//prototype for add_adj_mat_entry function
void add_adj_mat_entry(vector<vector<Edge>> &adj_m, Edge e, bool directed = 0);

int main()
{
    //the adjacency matrix, which consists of edges
    vector<vector<Edge>> adj_mat(4, vector<Edge>(4, Edge(INT_MAX,-1,-1)));

    add_adj_mat_entry(adj_mat, Edge(1,0,1));
    add_adj_mat_entry(adj_mat, Edge(3,0,2));
    add_adj_mat_entry(adj_mat, Edge(5,1,2));
    add_adj_mat_entry(adj_mat, Edge(1,2,3));

    //show the adjacency matrix for debugging

    int vertex = 0;
    cout << "\n 0 1 2 3";
    for(vector<Edge> sub_v: adj_mat)
    {
        cout << "\n";
        for(Edge e: sub_v)
        {
            if(e.weight == INT_MAX)
            {
                cout << " " << '*';
            }
            else
            {
                cout << " " << e.weight;
            }
        }

        cout << " " << vertex++;
    }

    //compute some shortest paths
    cout << "\n\nShortest path from 0 to 3: " 
            << shortest_distance(adj_mat, 0, 3) << "\n\n"
            << "\n\nShortest path from 3 to 0: " 
            << shortest_distance(adj_mat, 3, 0) << "\n\n"
            << "\n\nShortest path from 3 to 3: " 
            << shortest_distance(adj_mat, 3, 3) << "\n\n";

    return 0;
}

//given a pre-existing adjacency matrix (a 2D vector), an edge, and the
//optional parameter indicating whether or not the edge is directed, add
//the given edge to the adjacency matrix
void add_adj_mat_entry(vector<vector<Edge>> &adj_m, Edge e, bool directed)
{
    //add edge to inverted position in the adjacency matrix to reflect an
    //undirected graph
    if(!directed)
    {
        adj_m[e.endpt2][e.endpt1] = e;
    }
    
    //both directed and undirected graphs have this edge (it is assumed
    //endpt1 is the start and endpt2 is the finish)
    adj_m[e.endpt1][e.endpt2] = e;
}
