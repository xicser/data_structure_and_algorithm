#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

//顶点
class Edge;
class Node {
public:
    Node(int id) {
        this->id = id;
        this->in = 0;
        this->out = 0;
        nexts.clear();
        edges.clear();
    }

    int id;
    int in, out;
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
    void createGraph1(vector<vector<int>>& matrix, int line) {
        for (int i = 0; i < line; i++) {
            int weight = 1;

            int fromId = matrix[i][1];
            int toId = matrix[i][0];

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

            edges.insert(edge);
        }
    }

    /* 拓扑排序(只能适用于有向无环图) */
    vector<int> topologicalSort()
    {
        vector<int> result;

        //key某个顶点, value剩余的入度
        unordered_map<Node*, int> inMap;

        //只有剩余入度为0的点, 才进入这个队列
        queue<Node*> zeroInQueue;

        for (unordered_map<int, Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {

            Node* node = it->second;
            inMap[node] = node->in;

            if (node->in == 0) {
                zeroInQueue.push(node);
            }
        }
        if (zeroInQueue.size() == 0) {
            //一开始就没有入度为0的节点
            return {};
        }
        int visitCnt = 0;
        while (!zeroInQueue.empty()) {
            Node* node = zeroInQueue.front();
            zeroInQueue.pop();
            result.push_back(node->id);
            visitCnt++;

            //消除和这个顶点相邻的其他顶点的入度边
            for (unsigned int i = 0; i < node->nexts.size(); i++) {
                inMap[node->nexts[i]]--;
                if (inMap[node->nexts[i]] == 0) {
                    zeroInQueue.push(node->nexts[i]);
                }
            }
        }

        if (visitCnt == nodes.size()) {
            return result;
        }

        return {};
    }
    unordered_map<int, Node*>& getNodesMap() {
        return nodes;
    }

private:
    unordered_map<int, Node*> nodes;       //顶点集合<id, Node_Addr>
    unordered_set<Edge*> edges;            //边集合
};

class Solution {
private:
    Graph graph;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> result;
        //如果不需要先修课，则按顺序学就行
        if (prerequisites.size() == 0) {
            for (int i = 0; i < numCourses; i++) {
                result.push_back(i);
            }
            return result;
        }
        graph.createGraph1(prerequisites, prerequisites.size()); //创建图
        result = graph.topologicalSort();  //拓扑排序
        if (result.size() == 0) {
            return {};
        }

        //不存在依赖关系的课程
        unordered_map<int, Node*>& nodes = graph.getNodesMap();
        for (int i = 0; i < numCourses; i++) {
            if (nodes.find(i) == nodes.end()) {
                result.push_back(i);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> prerequisites = { {1,0},{2,6},{1,7},{5,1},{6,4},{7,0},{0,5} };
    vector<int> result = sol.findOrder(8, prerequisites);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
