#include <iostream>
#include "UndirectedGraphAdjMatrix.h"

using namespace std;

int main()
{
    UndirectedGraphAdjMatrix graph(6);
    graph.DFSRecursionPrepare();
    graph.DFSRecursion(0);

    graph.DFS(0);
    graph.BFS(0);
    graph.MST_Prim(0);
    graph.MST_Kruskal();

    return 0;
}
