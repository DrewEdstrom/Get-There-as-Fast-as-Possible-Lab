#include <vector>

//an edge of a graph, made up of a weight and two endpoints
class Edge
{
    public:

    int weight;
    int endpt1, endpt2;

    Edge(int new_weight, int new_endpt1, int new_endpt2);

};

//computes the shortest distance between start_n and end_n given an
//adjacency matrix. returns -1 if there is no way to reach end_n from
//start_n.
int shortest_distance(std::vector<std::vector<Edge>> &adj_mat, int start_n, int end_n);
