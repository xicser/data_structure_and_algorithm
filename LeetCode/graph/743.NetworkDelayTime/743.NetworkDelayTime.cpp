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
        delete[]heapArray;
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
    int extraDataDomain;
    vector<Node*> nexts;   //出度顶点
    vector<Edge*> edges;   //出度边
};

//边
class Edge {
public:
    Edge(int weight, Node* from, Node* to) {
        this->weight = weight;
        this->from = from;
        this->to = to;
    }

    int weight;    //边的权重
    Node* from;
    Node* to;
};

//图
class Graph {
public:
    Graph() {
        nodes.clear();
        edges.clear();
        distanceInf = 99999999;
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
    //times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    void createGraph1(int n, vector<vector<int>>& edges) {

        unordered_set<int> usedNode;
        for (int i = 0; i < edges.size(); i++) {

            int fromId = edges[i][0];
            int toId = edges[i][1];
            int weight = edges[i][2];

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

        //单独顶点
        for (int i = 1; i <= n; i++) {
            if (usedNode.count(i) == 0) {
                Node* node = new Node(i);
                nodes[i] = node;
            }
        }
    }

    //迪杰斯特拉
    int dijkstra(int start) {

        //从startNode出发到所有点的最小距离
        //key: 从startNode出发到key
        //value: 从startNode出发到key当前的最小距离
        unordered_map<Node*, int> distanceMap;

        //使用小根堆组织顶点
        Heap heap(nodes.size(), [](const void* a, const void* b) {
            return ((Node*)a)->extraDataDomain < ((Node*)b)->extraDataDomain;
        });

        Node* startNode = nodes[start];
        for (auto& it : nodes) {
            Node* node = it.second;
            if (node == startNode) {
                node->extraDataDomain = 0;
                heap.push(node);
            }
            else {
                node->extraDataDomain = distanceInf;
                heap.push(node);
            }
        }

        Node* minNode = (Node*)heap.top();
        heap.pop();
        while (minNode != nullptr) {

            int distanceCur = minNode->extraDataDomain;
            for (Edge* edgeNext : minNode->edges) {
                Node* to = edgeNext->to;
                int newDistance = distanceCur + edgeNext->weight;

                //如果通过新的桥连点到它所能到的节点的距离比以前小, 那么更新距离
                if (newDistance < to->extraDataDomain) {
                    to->extraDataDomain = newDistance;
                    heap.adjust(to);
                }
            }

            //保存结果
            distanceMap[minNode] = distanceCur;
            minNode = (Node*)heap.top();
            heap.pop();
        }

        int max = -1;
        for (auto& it : distanceMap) {
            int distance = it.second;
            if (distance == distanceInf) {
                return -1;
            }
            else if (max < distance) {
                max = distance;
            }
        }

        return max;
    }

private:
    unordered_map<int, Node*> nodes;       //顶点集合<id, Node_Addr>
    unordered_set<Edge*> edges;            //边集合
    int distanceInf;
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph graph;
        graph.createGraph1(n, times);
        return graph.dijkstra(k);
    }
};

int main()
{
    vector<vector<int>> times = { {2,1,1},{2,3,1},{3,4,1} };

    Solution sol;
    cout << sol.networkDelayTime(times, 4, 2) << endl;
}

