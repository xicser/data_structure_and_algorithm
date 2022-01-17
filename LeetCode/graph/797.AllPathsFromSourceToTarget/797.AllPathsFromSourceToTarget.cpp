#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

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

    int extraDataDomain;    //额外数据域
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
private:
    vector<vector<int>>& result;
    vector<int> path;

    unordered_map<int, Node*> nodes;       //顶点集合<id, Node_Addr>
    unordered_set<Edge*> edges;            //边集合

public:
    Graph(vector<vector<int>>& result) : result(result) {
        nodes.clear();
        edges.clear();
        path.push_back(0);
    }
    ~Graph() {
        for (unordered_map<int, Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
            delete it->second;
        }
        for (unordered_set<Edge*>::iterator it = edges.begin(); it != edges.end(); it++) {
            delete *it;
        }
    }

    //创建图
    void createGraph1(vector<vector<int>>& graph) {

        //[[1,2],[3],[3],[]]
        int size = graph.size();
        for (int i = 0; i < size; i++) {

            int weight = 1;

            int fromId = i;
            int toSize = graph[i].size();
            
            for (int j = 0; j < toSize; j++) {

                int toId = graph[i][j];

                Node* fromNode, * toNode;
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
    }

    //深度优先遍历
    void dfs(Node* node, unordered_set<Node*>& hasVisited) {
        
        if (node->id == nodes.size() - 1) {
            result.push_back(path);
            return;
        }

        for (Node* nextNode : node->nexts) {
            path.push_back(nextNode->id);
            dfs(nextNode, hasVisited);

            //回溯
            path.pop_back();
        }
    }

    //获取id顶点
    Node* getNode(int id) {
        return nodes[id];
    }
};

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> result;

        Graph graph1(result);
        graph1.createGraph1(graph);

        unordered_set<Node*> hasVisited;
        graph1.dfs(graph1.getNode(0), hasVisited);

        return result;
    }
};

int main()
{
    vector<vector<int>> graph = { {4,3,1},{3,2,4},{3},{4},{} };
    Solution sol;
    vector<vector<int>> result = sol.allPathsSourceTarget(graph);

    for (auto& item : result) {
        for (int i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}
