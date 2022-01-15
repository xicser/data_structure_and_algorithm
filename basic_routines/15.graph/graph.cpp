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

int Graph::distanceInf;

Graph::Graph()
{
    distanceInf = 99999999;
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
        que.pop();  //弹出就打印
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

/* 递归深度优先遍历 */
void Graph::dfs(Node* node, unordered_set<Node*>& hasVisited)
{
    if (node == nullptr) {
        return;
    }

    //如果当前这个节点已经被访问过
    if (hasVisited.find(node) != hasVisited.end()) {
        return;
    }

    printf("%d ", node->id);
    hasVisited.insert(node);

    for (Node* nextNode : node->nexts) {
        dfs(nextNode, hasVisited);
    }
}

/* 非递归深度优先遍历 */
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
    printf("%d ", pCur->id);  //进栈就打印
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

/* 拓扑排序(只能适用于有向无环图) */
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

    //创建并查集, 最开始每个结点自己是一个集合
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

            //如果节点已经全部连通了
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
unordered_set<Edge*> Graph::mstPrim(int nodeId)
{
    //小根堆, 存放解锁的边
    priority_queue<Edge *, vector<Edge *>, cmpPrim> edgesQueue;

    //存放已经加入小根堆的边
    unordered_set<Edge *> edgesSet;

    //存放解锁的顶点
    unordered_set<Node *> nodesSet;

    //存放结果
    unordered_set<Edge *> result;

    //出发点
    Node* nodeStart = nodes[nodeId];

    if (nodesSet.count(nodeStart) == 0) {
        nodesSet.insert(nodeStart); //先把开始的顶点存放进点集

        //然后把开始顶点的临近边加到小根堆中
        for (Edge* nearEdge: nodeStart->edges) {
            if (edgesSet.count(nearEdge) == 0) {
                edgesQueue.push(nearEdge);
                edgesSet.insert(nearEdge); //set同步更新
            }
        }

        while (edgesQueue.empty() == false) {
            Edge* edgeMin = edgesQueue.top();
            edgesQueue.pop();

            Node* toNode = edgeMin->to;
            if (nodesSet.count(toNode) == 0) { //to点不在集合里, 表明要这条边
                nodesSet.insert(toNode);
                result.insert(edgeMin);        //存放结果
                
                //新点解锁新边
                for (Edge* nearEdge : toNode->edges) {
                    if (edgesSet.count(nearEdge) == 0) {
                        edgesQueue.push(nearEdge);
                        edgesSet.insert(nearEdge); //set同步更新
                    }
                }
            }
        }
    }

    return result;
}

/* 迪杰斯特拉
返回从startNode开始, 到每个节点的最短路径长度
*/
unordered_map<Node *, int> Graph::dijkstra1(Node *startNode)
{
    //从startNode出发到所有点的最小距离
    //key: 从startNode出发到key
    //value: 从startNode出发到key当前的最小距离
    unordered_map<Node*, int> distanceMap;
    for (auto it : nodes) {
        Node* node = it.second;
        if (node == startNode) {
            distanceMap[startNode] = 0;
        }
        else {
            distanceMap[node] = distanceInf;
        }
    }

    //已经计算好的点, 之后不能再动了
    unordered_set<Node*> lockSet;

    Node* minNode = getMinNodeExceptLockNodes(lockSet, distanceMap);
    while (minNode != nullptr) {
        int distanceCur = distanceMap[minNode];
        for (Edge* edgeNext : minNode->edges) {
            Node* to = edgeNext->to;
            int newDistance = distanceCur + edgeNext->weight;
            
            //如果通过新的桥连点到它所能到的节点的距离比以前小, 那么更新距离
            if (newDistance < distanceMap[to]) {
                distanceMap[to] = newDistance;
            }
        }
        lockSet.insert(minNode); //把这个节点锁住
        minNode = getMinNodeExceptLockNodes(lockSet, distanceMap);
    }

    return distanceMap;
}

//从distanceMap中找到一个当前距离最小的顶点, 要求这个顶点不在lockSet中
Node* Graph::getMinNodeExceptLockNodes(unordered_set<Node*>& lockSet,
    unordered_map<Node*, int>& distanceMap)
{
    Node* minNode = nullptr;
    int minDis = INT_MAX;
    for (auto it : distanceMap) {
        Node* node = it.first;
        int distance = it.second;
        if (lockSet.count(node) == 0 && distance < minDis) {
            minNode = node;
            minDis = distance;
        }
    }

    return minNode;
}

/* 获取id顶点 */
Node *Graph::getNode(int id)
{
    return nodes[id];
}
