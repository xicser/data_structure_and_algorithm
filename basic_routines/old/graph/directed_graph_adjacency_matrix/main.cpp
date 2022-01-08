#include <iostream>
#include "DirectedGraphAdjMatrix.h"

using namespace std;

int main()
{
    DirectedGraphAdjMatrix graph1(7);
    graph1.Dijkstra(0);

    graph1.Floyd();
//    graph1.printFloydDistance(6, 0);
    printf("\n%d", graph1.getFloyDistanceBetween(0, 6));

//    DirectedGraphAdjMatrix graph2(4);
//    graph2.Dijkstra(0);
//    graph2.Floyd();

    return 0;
}
