#include "graph.h"


Node::Node(int id)
{
    this->id = id;
    this->in = 0;
    this->out = 0;
    nexts.clear();
    edges.clear();
}

Edge::Edge(int weight, Node *from, Node *to)
{
    this->weight = weight;
    this->from = from;
    this->to = to;
}

int Graph::distaceInf;

Graph::Graph()
{
    distaceInf = 9999999;
    nodes.clear();
    edges.clear();
}

Graph::~Graph()
{
    for (unordered_map<int, Node *>::iterator it = nodes.begin(); it != nodes.end(); it++) {
        delete it->second;
    }

    for (unordered_set<Edge *>::iterator it = edges.begin(); it != edges.end(); it++) {
        delete *it;
    }
}

/* 创建图
 matrix 所有的边
 N * 3的矩阵
 [weight, from节点id, to节点id]

 7 0 4
 4 1 3
 3 2 3
 8 2 4
 6 3 4

*/
void Graph::createGraph1(int matrix[][3], int line)
{
    for (int i = 0; i < line; i++) {
        int weight = matrix[i][0];

        int fromId = matrix[i][1];
        int toId = matrix[i][2];

        Node *fromNode, *toNode;
        Edge *edge;

        if (nodes.find(fromId) == nodes.end()) {
            fromNode = new Node(fromId);
            nodes[fromId] = fromNode;
        }
        else {
            fromNode = nodes[fromId];
        }

        if (nodes.find(toId) == nodes.end()) {
            toNode = new Node(toId);
            nodes[toId] = toNode;
        }
        else {
            toNode = nodes[toId];
        }

        //新建一条边
        edge = new Edge(weight, fromNode, toNode);

        fromNode->out++;
        toNode->in++;
        fromNode->nexts.push_back(toNode);
        fromNode->edges.push_back(edge);

        edges.insert(edge);
    }
}

/* 广度优先遍历 */
void Graph::bfs(Node *start)
{
    if (start == nullptr) {
        return;
    }

    queue<Node *> que;
    unordered_set<Node *> hasVisited;  //标记是否被访问过

    Node *pCur = start;
    que.push(pCur);
    hasVisited.insert(pCur);
    while (!que.empty()) {

        pCur = que.front();
        que.pop();
        printf("%d ", pCur->id);

        for (unsigned int i = 0; i < pCur->nexts.size(); i++) {
            //如果没有被访问过
            if (hasVisited.find(pCur->nexts[i]) == hasVisited.end()) {
                que.push(pCur->nexts[i]);
                hasVisited.insert(pCur->nexts[i]);
            }
        }
    }
    printf("\n");
}

/* 深度优先遍历 */
void Graph::dfs(Node *start)
{
    if (start == nullptr) {
        return;
    }

    stack<Node *> st;   //深度优先遍历的路径
    unordered_set<Node *> hasVisited;

    Node *pCur = start;
    st.push(pCur);
    hasVisited.insert(pCur);
    printf("%d ", pCur->id);
    while (!st.empty()) {

        Node *pCur = st.top();
        st.pop();
        for (unsigned int i = 0; i < pCur->nexts.size(); i++) {
            //如果没有被访问过
            if (hasVisited.find(pCur->nexts[i]) == hasVisited.end()) {
                st.push(pCur);
                st.push(pCur->nexts[i]);
                hasVisited.insert(pCur->nexts[i]);
                printf("%d ", pCur->nexts[i]->id);
                break;
            }
        }
    }
    printf("\n");
}

/* 拓扑排序(只能有向无环图) */
void Graph::topologicalSort()
{
    //key某个顶点, value剩余的入度
    unordered_map<Node *, int> inMap;

    //只有剩余入度为0的点, 才进入这个队列
    queue<Node *> zeroInQueue;

    for (unordered_map<int, Node *>::iterator it = nodes.begin(); it != nodes.end(); it++) {

        Node *node = it->second;
        inMap[node] = node->in;

        if (node->in == 0) {
            zeroInQueue.push(node);
        }
    }

    vector<int> result;
    while (!zeroInQueue.empty()) {
        Node *node = zeroInQueue.front();
        zeroInQueue.pop();
        printf("%d ", node->id);

        //消除和这个顶点相邻的其他顶点的入度边
        for (unsigned int i = 0; i < node->nexts.size(); i++) {
            inMap[ node->nexts[i] ]--;
            if (inMap[node->nexts[i]] == 0) {
                zeroInQueue.push(node->nexts[i]);
            }
        }
    }

    printf("\n");
}

/* 最小生成树Kruskal算法(只适用于无向图) */
struct cmpKruskal {
    bool operator () (Edge *e1, Edge *e2) {
        return e1->weight > e2->weight;
    }
};
static Node *findRoot(Node *node, unordered_map<Node *, Node *> &unionSet)
{
    while (unionSet[node] != node) {
        node = unionSet[node];
    }

    return node;
}

void Graph::mstKruskal()
{
    //小根堆, 自动给边按照代价排序
    priority_queue<Edge *, vector<Edge *>, cmpKruskal> edgesQueue;
    for (unordered_set<Edge *>::iterator it = edges.begin(); it != edges.end(); it++) {
        edgesQueue.push(*it);
    }

    //创建并查集
    unordered_map<Node *, Node *> unionSetNode;
    for (unordered_map<int, Node *>::iterator it = nodes.begin(); it != nodes.end(); it++) {
        unionSetNode[it->second] = it->second;
    }

    unsigned int cnt = 0;
    while (!edgesQueue.empty()) {

        Edge *edge = edgesQueue.top();
        edgesQueue.pop();

        Node *fromNode = edge->from;
        Node *toNode = edge->to;

        Node *root1 = findRoot(fromNode, unionSetNode);
        Node *root2 = findRoot(toNode, unionSetNode);

        if (root1 != root2) {
            //合并
            unionSetNode[root1] = root2;

            //打印这条边
            printf("edge = (%d) %d %d\n", edge->weight, fromNode->id, toNode->id);
            cnt++;

            //如果节点已经全部联通了
            if (cnt == nodes.size() - 1) {
                break;
            }
        }
    }
}

//最小生成树Prim算法(只适用于无向图)
struct cmpPrim {
    bool operator () (Edge *e1, Edge *e2) {
        return e1->weight > e2->weight;
    }
};
void Graph::mstPrim(int nodeId)
{
    unordered_set<Node *> nodesU;
    unordered_set<Node *> nodesV;

    //先把第一个顶点放到nodesU中
    nodesU.insert(nodes[nodeId]);

    //把剩下的顶点放到nodesV
    for (unordered_map<int, Node *>::iterator it = nodes.begin(); it != nodes.end(); it++) {
        Node *node = it->second;
        if (node != nodes[nodeId]) {
            nodesV.insert(node);
        }
    }

    priority_queue<Edge *, vector<Edge *>, cmpPrim> edgesQueue;
    while (nodesV.size() > 0) {

        //针对U中的每个顶点,
        //计算该顶点到V中各个顶点的边的代价,
        //记录这些边中代价最小的那个
        while (!edgesQueue.empty()) edgesQueue.pop();
        for (unordered_set<Node *>::iterator it = nodesU.begin(); it != nodesU.end(); it++) {
            Node *nodeCur = *it;
            Edge *edgeMinTmp;
            int weightMin = distaceInf;
            for (unsigned int i = 0; i < nodeCur->edges.size(); i++) {

                Edge *edgeTmp = nodeCur->edges[i];
                //如果这条边的对端在V里, 说明这条边是新边, 才会被考虑
                if (nodesV.find(edgeTmp->to) != nodesV.end()) {

                    if (edgeTmp->weight < weightMin) {
                        edgeMinTmp = edgeTmp;
                        weightMin = edgeTmp->weight;
                    }
                }
            }
            edgesQueue.push(edgeMinTmp);
        }

        //打印这条边
        Edge *edgeRes = edgesQueue.top();
        Node *fromNode = edgeRes->from;
        Node *toNode = edgeRes->to;
        printf("edge = (%d) %d %d\n", edgeRes->weight, fromNode->id, toNode->id);

        nodesU.insert(toNode);
        nodesV.erase(nodesV.find(toNode));
    }
}

/* 迪杰斯特拉 */
//路径
typedef struct {
    bool isDone;
    int distance;            //路径长度
    vector<Node *> vertexes; //路径上的顶点
} Route_t;
void Graph::dijkstra(Node *startNode)
{
    unordered_map<Node *, Route_t> routes;  //<顶点地址, 路径>
    vector<Route_t> resultRoutes; //结果

    //先初始化第一列
    unordered_set<Node *> addedNodes;
    int disMin = distaceInf;
    Node *disMinNode;
    for (unsigned int i = 0; i < startNode->edges.size(); i++) {
        Edge *nextEdge = startNode->edges[i];
        Node *toNode;
        toNode = nextEdge->to;

        Route_t routeTmp;
        routeTmp.distance = nextEdge->weight;

        //选出距离最短的哪个
        if (disMin > routeTmp.distance) {
            disMin = routeTmp.distance;
            disMinNode = toNode;
        }

        routeTmp.vertexes.push_back(startNode);
        routeTmp.vertexes.push_back(toNode);
        addedNodes.insert(toNode);
        routes[toNode] = routeTmp;
    }
    for (unordered_map<int, Node *>::iterator it = nodes.begin(); it != nodes.end(); it++) {

        Node *nodeTmp = it->second;
        if (addedNodes.find(nodeTmp) == addedNodes.end()) {

            Route_t routeTmp;
            routeTmp.distance = distaceInf;
            routeTmp.isDone = false;
            routeTmp.vertexes.push_back(startNode);
            routeTmp.vertexes.push_back(nodeTmp);
            routes[nodeTmp] = routeTmp;
        }
    }
    //把距离最短的那个结果存放到已完成vector中
    resultRoutes.push_back(routes[disMinNode]);
    routes[disMinNode].isDone = true;

    //开始处理
    int times = nodes.size() - 2;
    Node *startNew = disMinNode;
    int lastDist = routes[disMinNode].distance;
    for (int i = 0; i < times; i++) {

        for (unordered_map<int, Node *>::iterator it = nodes.begin(); it != nodes.end(); it++) {
            Node *tmpNode = it->second;
            if (tmpNode == startNode || routes[tmpNode].isDone == true) {
                continue;
            }

//            //需要更新
//            if (lastDist + ) {
//
//            }






        }


        //将本轮最小的那个加入resultRoutes


    }

    //输出


}











/* 获取id顶点 */
Node *Graph::getNode(int id)
{
    return nodes[id];
}














