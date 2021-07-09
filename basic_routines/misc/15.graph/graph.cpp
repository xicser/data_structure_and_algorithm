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


Graph::Graph()
{
    nodes.clear();
    edges.clear();
}

Graph::~Graph()
{
    for (map<int, Node *>::iterator it = nodes.begin(); it != nodes.end(); it++) {
        delete it->second;
    }

    for (set<Edge *>::iterator it = edges.begin(); it != edges.end(); it++) {
        delete *it;
    }
}

/* ����ͼ
 matrix ���еı�
 N * 3�ľ���
 [weight, from�ڵ�id, to�ڵ�id]

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

        //�½�һ����
        edge = new Edge(weight, fromNode, toNode);

        fromNode->out++;
        toNode->in++;
        fromNode->nexts.push_back(toNode);
        fromNode->edges.push_back(edge);

        edges.insert(edge);
    }
}

/* ������ȱ��� */
void Graph::bfs(Node *start)
{
    if (start == nullptr) {
        return;
    }

    queue<Node *> que;
    set<Node *> hasVisited;

    Node *pCur = start;
    que.push(pCur);
    hasVisited.insert(pCur);
    while (!que.empty()) {

        pCur = que.front();
        que.pop();
        printf("%d ", pCur->id);

        for (unsigned int i = 0; i < pCur->nexts.size(); i++) {
            //���û�б����ʹ�
            if (hasVisited.find(pCur->nexts[i]) == hasVisited.end()) {
                que.push(pCur->nexts[i]);
                hasVisited.insert(pCur->nexts[i]);
            }
        }
    }
    printf("\n");
}

/* ������ȱ��� */
void Graph::dfs(Node *start)
{
    if (start == nullptr) {
        return;
    }

    stack<Node *> st;   //������ȱ�����·��
    set<Node *> hasVisited;

    Node *pCur = start;
    st.push(pCur);
    hasVisited.insert(pCur);
    printf("%d ", pCur->id);
    while (!st.empty()) {

        Node *pCur = st.top();
        st.pop();
        for (unsigned int i = 0; i < pCur->nexts.size(); i++) {
            //���û�б����ʹ�
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

/* ��������(ֻ�������޻�ͼ) */
void Graph::topologicalSort()
{
    //keyĳ������, valueʣ������
    map<Node *, int> inMap;

    //ֻ��ʣ�����Ϊ0�ĵ�, �Ž����������
    queue<Node *> zeroInQueue;

    for (map<int, Node *>::iterator it = nodes.begin(); it != nodes.end(); it++) {

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

        //����������������ڵ������������ȱ�
        for (unsigned int i = 0; i < node->nexts.size(); i++) {
            inMap[ node->nexts[i] ]--;
            if (inMap[node->nexts[i]] == 0) {
                zeroInQueue.push(node->nexts[i]);
            }
        }
    }

    printf("\n");
}

/* ��С������Kruskal�㷨(ֻ����������ͼ) */
struct cmpKruskal {
    bool operator () (Edge *e1, Edge *e2) {
        return e1->weight > e2->weight;
    }
};
static Node *findRoot(Node *node, map<Node *, Node *> &unionSet)
{
    while (unionSet[node] != node) {
        node = unionSet[node];
    }

    return node;
}

void Graph::mstKruskal()
{
    //С����, �Զ����߰��մ�������
    priority_queue<Edge *, vector<Edge *>, cmpKruskal> edgesQueue;
    for (set<Edge *>::iterator it = edges.begin(); it != edges.end(); it++) {
        edgesQueue.push(*it);
    }

    //�������鼯
    map<Node *, Node *> unionSetNode;
    for (map<int, Node *>::iterator it = nodes.begin(); it != nodes.end(); it++) {
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
            //�ϲ�
            unionSetNode[root1] = root2;

            //��ӡ������
            printf("edge = (%d) %d %d\n", edge->weight, fromNode->id, toNode->id);
            cnt++;

            //����ڵ��Ѿ�ȫ����ͨ��
            if (cnt == nodes.size() - 1) {
                break;
            }
        }
    }
}

//��С������Prim�㷨(ֻ����������ͼ)
struct cmpPrim {
    bool operator () (Edge *e1, Edge *e2) {
        return e1->weight > e2->weight;
    }
};
void Graph::mstPrim(int nodeId)
{
    set<Node *> nodesU;
    set<Node *> nodesV;

    //�Ȱѵ�һ������ŵ�nodesU��
    nodesU.insert(nodes[nodeId]);

    //��ʣ�µĶ���ŵ�nodesV
    for (map<int, Node *>::iterator it = nodes.begin(); it != nodes.end(); it++) {
        Node *node = it->second;
        if (node != nodes[nodeId]) {
            nodesV.insert(node);
        }
    }

    priority_queue<Edge *, vector<Edge *>, cmpPrim> edgesQueue;
    while (nodesV.size() > 0) {

        //���U�е�ÿ������,
        //����ö��㵽V�и�������ıߵĴ���,
        //��¼��Щ���д�����С���Ǹ�
        while (!edgesQueue.empty()) edgesQueue.pop();
        for (set<Node *>::iterator it = nodesU.begin(); it != nodesU.end(); it++) {
            Node *nodeCur = *it;
            Edge *edgeMinTmp;
            int weightMin = 9999999;
            for (unsigned int i = 0; i < nodeCur->edges.size(); i++) {

                Edge *edgeTmp = nodeCur->edges[i];
                //��������ߵĶԶ���V��, ˵�����������±�, �Żᱻ����
                if (nodesV.find(edgeTmp->to) != nodesV.end()) {

                    if (edgeTmp->weight < weightMin) {
                        edgeMinTmp = edgeTmp;
                        weightMin = edgeTmp->weight;
                    }
                }
            }
            edgesQueue.push(edgeMinTmp);
        }

        //��ӡ������
        Edge *edgeRes = edgesQueue.top();
        Node *fromNode = edgeRes->from;
        Node *toNode = edgeRes->to;
        printf("edge = (%d) %d %d\n", edgeRes->weight, fromNode->id, toNode->id);

        nodesU.insert(toNode);
        nodesV.erase(nodesV.find(toNode));
    }
}













/* ��ȡid���� */
Node *Graph::getNode(int id)
{
    return nodes[id];
}














