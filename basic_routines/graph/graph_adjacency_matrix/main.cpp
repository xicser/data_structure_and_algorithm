#include <iostream>
#include "GraphAdjMatrix.h"

using namespace std;

int main()
{
    GraphAdjMatrix graph(6);
    graph.DFSRecursionPrepare();
    graph.DFSRecursion(0);

    graph.DFS(0);
    graph.BFS(0);
    graph.MST_Prim(0);

    return 0;
}
