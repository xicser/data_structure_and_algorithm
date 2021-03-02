#include <iostream>
#include "GraphAdjMatrix.h"

using namespace std;

int main()
{
    GraphAdjMatrix graph(6);
    graph.DFSRecursionPrepare();
    graph.DFSRecursion(1);

    graph.DFS(0);
    graph.BFS(1);

    return 0;
}
