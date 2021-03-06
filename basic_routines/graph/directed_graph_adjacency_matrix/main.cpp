#include <iostream>
#include "DirectedGraphAdjMatrix.h"

using namespace std;

int main()
{
    DirectedGraphAdjMatrix graph(7);
    graph.Dijkstra(0);

    return 0;
}
