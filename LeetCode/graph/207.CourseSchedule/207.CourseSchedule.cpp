#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

////顶点
//class Edge;
//class Node {
//public:
//    Node(int id) {
//        this->id = id;
//        this->in = 0;
//        this->out = 0;
//        nexts.clear();
//        edges.clear();
//    }
//
//    int id;
//    int in, out;
//    vector<Node*> nexts;   //出度顶点
//    vector<Edge*> edges;   //出度边
//};
//
////边
//class Edge {
//public:
//    Edge(int weight, Node* from, Node* to) {
//        this->weight = weight;
//        this->from = from;
//        this->to = to;
//    }
//
//    int weight;    //边的权重
//    Node* from;
//    Node* to;
//};
//
////图
//class Graph {
//public:
//    Graph() {
//        nodes.clear();
//        edges.clear();
//    }
//    ~Graph() {
//        for (unordered_map<int, Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
//            delete it->second;
//        }
//        for (unordered_set<Edge*>::iterator it = edges.begin(); it != edges.end(); it++) {
//            delete* it;
//        }
//    }
//
//    //创建图
//    void createGraph1(vector<vector<int>>& matrix, int line) {
//        for (int i = 0; i < line; i++) {
//            int weight = 1;
//
//            int fromId = matrix[i][0];
//            int toId = matrix[i][1];
//
//            Node* fromNode, * toNode;
//            Edge* edge;
//
//            if (nodes.find(fromId) == nodes.end()) {
//                fromNode = new Node(fromId);
//                nodes[fromId] = fromNode;
//            }
//            else {
//                fromNode = nodes[fromId];
//            }
//
//            if (nodes.find(toId) == nodes.end()) {
//                toNode = new Node(toId);
//                nodes[toId] = toNode;
//            }
//            else {
//                toNode = nodes[toId];
//            }
//
//            //新建一条边
//            edge = new Edge(weight, fromNode, toNode);
//
//            fromNode->out++;
//            toNode->in++;
//            fromNode->nexts.push_back(toNode);
//            fromNode->edges.push_back(edge);
//
//            edges.insert(edge);
//        }
//    }
//
//    /* 拓扑排序(只能适用于有向无环图) */
//    bool topologicalSort()
//    {
//        //key某个顶点, value剩余的入度
//        unordered_map<Node*, int> inMap;
//
//        //只有剩余入度为0的点, 才进入这个队列
//        queue<Node*> zeroInQueue;
//
//        for (unordered_map<int, Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
//
//            Node* node = it->second;
//            inMap[node] = node->in;
//
//            if (node->in == 0) {
//                zeroInQueue.push(node);
//            }
//        }
//        if (zeroInQueue.size() == 0) {
//            //一开始就没有入度为0的节点
//            return false;
//        }
//        int visitCnt = 0;
//        vector<int> result;
//        while (!zeroInQueue.empty()) {
//            Node* node = zeroInQueue.front();
//            zeroInQueue.pop();
//            visitCnt++;
//
//            //消除和这个顶点相邻的其他顶点的入度边
//            for (unsigned int i = 0; i < node->nexts.size(); i++) {
//                inMap[node->nexts[i]]--;
//                if (inMap[node->nexts[i]] == 0) {
//                    zeroInQueue.push(node->nexts[i]);
//                }
//            }
//        }
//
//        return visitCnt == nodes.size();
//    }
//
//private:
//    unordered_map<int, Node*> nodes;       //顶点集合<id, Node_Addr>
//    unordered_set<Edge*> edges;            //边集合
//};
//class Solution {
//private:
//    Graph graph;
//
//public:
//    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//        if (prerequisites.size() == 0) {
//            return true;
//        }
//        graph.createGraph1(prerequisites, prerequisites.size()); //创建图
//        return graph.topologicalSort();  //拓扑排序
//    }
//};


class Solution {
private:
    unordered_map<int, unordered_set<int> > adjMaxtrix;     //邻接表<node, nextNodes>

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> inCntMap(numCourses, 0);                          //记录每个点的入度<node, inCnt>

        // 创建图的邻接表
        for (int i = 0; i < prerequisites.size(); i++) {
            int from = prerequisites[i][1];
            int to = prerequisites[i][0];
            adjMaxtrix[from].insert(to);

            inCntMap[to]++;
        }

        return topologicalSort(inCntMap);
    }

    /* 拓扑排序(只能适用于有向无环图) */
    bool topologicalSort(vector<int>& inCntMap)
    {
        vector<int> result;
        queue<int> que;

        //将入度为0的点都加进去
        for (int i = 0; i < inCntMap.size(); i++) {
            if (inCntMap[i] == 0) {
                que.push(i);
            }
        }

        while (que.size() != 0) {
            int node = que.front();
            que.pop();
            result.push_back(node);

            //删除这个入度为0的点之后, 消除这个点临近的所有边
            unordered_set<int> nextNodes = adjMaxtrix[node];

            for (int next : nextNodes) {
                inCntMap[next]--;
                if (inCntMap[next] == 0) {
                    que.push(next);
                }
            }
        }

        return result.size() == inCntMap.size();
    }
};

int main()
{
    vector<vector<int>> prerequisites = { {1, 4}, {2, 4}, {3, 1},{3, 2} };
    Solution sol;
    
    std::cout << sol.canFinish(5, prerequisites) << endl;

    return 0;
}
