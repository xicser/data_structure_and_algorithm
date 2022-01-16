#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <functional>

using namespace std;

class Heap {
private:
    int heapSize;
    int heapSizeLimit;
    void** heapArray;
    //比较器, 用于确定堆中元素的"逻辑大小关系"
    function<bool(const void* a, const void* b)> comparator;

    //记录当前堆上某个节点在数组中的下标
    unordered_map<void*, int> indexMap;

    void heapInsert(int index) {
        //比他爸爸"大"
        while (comparator(heapArray[index],             //孩子
            heapArray[(index - 1) / 2])                 //爸爸
            == true) {
            swap(index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }
    void heapify(int index) {
        if (heapSize == 0) {
            return;
        }

        //左孩子下标
        int left = index * 2 + 1;

        //有左孩子
        while (left < heapSize) {

            //获取左右孩子中大的那个孩子的下标
            //右孩子存在且右孩子的值大于左孩子, 右孩子胜出, 否则左孩子胜出
            int right = left + 1;
            int largest = right < heapSize&& comparator(heapArray[right], heapArray[left]) == true ? right : left;

            //当前节点和较大孩子节点比较大小, 取较大的那个的下标
            largest = comparator(heapArray[largest], heapArray[index]) == true ? largest : index;

            //两个孩子没有一个能干过当前父亲
            if (largest == index) {
                break;
            }

            swap(index, largest);
            index = largest;
            left = index * 2 + 1;
        }
    }
    void swap(int i, int j) {
        //同步更新indexMap
        void* a = heapArray[i];
        void* b = heapArray[j];
        indexMap[a] = j;
        indexMap[b] = i;

        void* tmp = heapArray[i];
        heapArray[i] = heapArray[j];
        heapArray[j] = tmp;
    }

public:
    Heap(int limit, function<bool(const void* a, const void* b)> comparator) {
        this->heapSizeLimit = limit;
        this->heapSize = 0;
        this->heapArray = new void* [this->heapSizeLimit];
        this->comparator = comparator;
    }
    ~Heap() {
        delete []heapArray;
    }
    void  push(void* value) {
        if (heapSize == heapSizeLimit) {
            return;
        }

        heapArray[heapSize] = value;
        indexMap[value] = heapSize;  //同步更新indexMap

        heapInsert(heapSize);
        heapSize++;
    }
    void* top() {
        if (heapSize == 0) {
            return nullptr;
        }

        return heapArray[0];
    }
    void  pop() {
        if (heapSize == 0) {
            return;
        }

        //同步更新indexMap
        indexMap.erase(heapArray[0]);

        heapSize--;
        heapArray[0] = heapArray[heapSize];

        //同步更新indexMap
        indexMap[heapArray[0]] = 0;

        heapify(0);
    }
    void adjust(void* value) {
        int index = indexMap[value];
        heapInsert(index);
        heapify(index);
    }
    bool empty() {
        return heapSize == 0;
    }
    bool full() {
        return heapSize == heapSizeLimit;
    }
    int size() {
        return this->heapSize;
    }
};

//顶点
class Edge;
class Node {
public:
    Node(int id) {
        this->id = id;
        this->in = 0;
        this->out = 0;
        this->extraDataDomain = 0;
        nexts.clear();
        edges.clear();
    }

    int id;
    int in, out;
    double extraDataDomain;
    vector<Node*> nexts;   //出度顶点
    vector<Edge*> edges;   //出度边
};

//边
class Edge {
public:
    Edge(double weight, Node* from, Node* to) {
        this->weight = weight;
        this->from = from;
        this->to = to;
    }

    double weight;    //边的权重
    Node* from;
    Node* to;
};

//图
class Graph {
public:
    Graph() {
        nodes.clear();
        edges.clear();
    }
    ~Graph() {
        for (unordered_map<int, Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
            delete it->second;
        }
        for (unordered_set<Edge*>::iterator it = edges.begin(); it != edges.end(); it++) {
            delete* it;
        }
    }

    //创建图
    //n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2],
    void createGraph1(int n, vector<vector<int>>& edges, vector<double>& succProb) {

        unordered_set<int> usedNode;
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < edges.size(); i++) {

                int fromId, toId;
                double weight = succProb[i];
                if (k == 0) {
                    fromId = edges[i][0];
                    toId = edges[i][1];
                }
                else {
                    fromId = edges[i][1];
                    toId = edges[i][0];
                }

                //记录当前已经用过的顶点id
                usedNode.insert(fromId);
                usedNode.insert(toId);

                Node* fromNode, *toNode;
                Edge* edge;
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

                this->edges.insert(edge);
            }
        }

        //单独顶点
        for (int i = 0; i < n; i++) {
            if (usedNode.count(i) == 0) {
                Node* node = new Node(i);
                nodes[i] = node;
            }
        }
    }

    //迪杰斯特拉
    double dijkstra(int start, int end) {

        Node* startNode = nodes[start];
        //从startNode出发到所有点的最大概率的值
        //key: 从startNode出发到key
        //value: 从startNode出发到key当前的最大概率值
        unordered_map<Node*, double> probMap;

        //使用大根堆组织顶点
        Heap heap(nodes.size(), [](const void* a, const void* b) {
            return ((Node*)a)->extraDataDomain > ((Node*)b)->extraDataDomain;
        });
        for (auto it : nodes) {
            Node* node = it.second;
            if (node == startNode) {
                node->extraDataDomain = 1;
                heap.push(node);
            }
            else {
                node->extraDataDomain = 0;
                heap.push(node);
            }
        }

        //已经计算好的点, 之后不能再动了
        unordered_set<Node*> lockSet;

        Node* maxNode = (Node*)heap.top();
        heap.pop();
        while (maxNode != nullptr) {
            double probCur = maxNode->extraDataDomain;

            for (Edge* edgeNext : maxNode->edges) {
                Node* to = edgeNext->to;
                if (lockSet.count(to) != 0) {
                    continue;
                }

                double newProb = probCur * edgeNext->weight;

                //如果通过新的桥连点到它所能到的节点的概率比以前大, 那么更新概率
                if (newProb > to->extraDataDomain) {
                    to->extraDataDomain = newProb;
                    heap.adjust(to);
                }
            }
            lockSet.insert(maxNode);    //把这个节点锁住
            probMap[maxNode] = probCur; //保存结果

            maxNode = (Node*)heap.top();
            heap.pop();
        }

        return probMap[ nodes[end] ];
    }

private:
    Node* getMaxNodeExceptLockNodes(unordered_set<Node*>& lockSet,
        unordered_map<Node*, double>& probMap) {

        Node* maxNode = nullptr;
        double maxProb = -1;
        for (auto it : probMap) {
            Node* node = it.first;
            double prob = it.second;
            if (lockSet.count(node) == 0 && prob > maxProb) {
                maxNode = node;
                maxProb = prob;
            }
        }

        return maxNode;
    }

    unordered_map<int, Node*> nodes;       //顶点集合<id, Node_Addr>
    unordered_set<Edge*> edges;            //边集合
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        Graph graph;
        graph.createGraph1(n, edges, succProb);
        return graph.dijkstra(start, end);
    }
};

int main()
{
    vector<vector<int>> edges = { {0,1} ,{1,2},{0,2} };
    vector<double> succProb = { 0.5, 0.5, 0.3 };
    Solution sol;
    cout << sol.maxProbability(3, edges, succProb, 0, 2) << endl;
}

