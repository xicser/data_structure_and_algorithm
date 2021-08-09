/*

Shortest Distance

*/

#include <iostream>
#include <stdio.h>

using namespace std;


//�����������֮�����̾���
int cal_distance(int dist_all, int *dist, int node1, int node2)
{
    int node_min = min(node1, node2);
    int node_max = max(node1, node2);
    int dist_plus = 0, dist_minus = 0;

    //�ȼ�������ľ���
    if (node_min == 0) {
        dist_plus = dist[node_max - 1];
    } else {
        dist_plus = dist[node_max - 1] - dist[node_min - 1];
    }

    //�ټ��㸺��ľ���
    dist_minus = dist_all - dist_plus;

    return (dist_plus > dist_minus) ? dist_minus : dist_plus;
}

int dist[100005]; //dist[i]��ʾnode0��node(i + 1)�ľ���(�����д�node�ı��0��ʼ��)
int main()
{
    int dist_all = 0;
    int node_cnt;
    scanf("%d", &node_cnt);
    int nodes_distance[node_cnt];
    for (int i = 0; i < node_cnt; i++) {
        scanf("%d", &nodes_distance[i]);
        dist_all += nodes_distance[i];
        dist[i] = dist_all;
    }

    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        printf("%d\n", cal_distance(dist_all, dist, node1 - 1, node2 - 1));  //�����д�node�ı��0��ʼ��
    }

    return 0;
}
