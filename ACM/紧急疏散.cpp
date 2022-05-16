#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

int vertexCount;

//邻接表
unordered_map<int, vector<int> > adjList;

int dfs(int startVertexId, vector<bool>& isVisited);
int main()
{
    int n;
    cin >> n;

    vertexCount = n;

    //顶点访问标记
    vector<bool> isVisited(vertexCount, false);

    for (int i = 0; i < vertexCount - 1; i++) {

        int node1, node2;
        cin >> node1 >> node2;
        node1--;
        node2--;

        int key = node1;
        vector<int> &vec1 = adjList[key];
        vec1.push_back(node2);
        //adjList[key] = vec1;

        key = node2;
        vector<int> &vec2 = adjList[key];
        vec2.push_back(node1);
        //adjList[key] = vec2;
    }

    //遍历根节点的子节点, 看哪个节点个数最多
    isVisited[0] = true;    //根节点已经访问过
    int maxVal = 0;

    vector<int> rootNeibor = adjList[0];
    for (int next : rootNeibor) {
        
        int temp = dfs(next, isVisited);
        maxVal = max(temp, maxVal);
    }

    cout << maxVal << endl;

    return 0;
}

//返回当前这个树的节点个数
int dfs(int startVertexId, vector<bool>& isVisited)
{
    if (isVisited[startVertexId] == true) {
        return 0;
    }

    isVisited[startVertexId] = true;             //标记该顶点已经被访问过

    int maxVal = 0;
    int key = startVertexId;
    vector<int> rootNeibor = adjList[key];
    for (int next : rootNeibor) {
        int temp = dfs(next, isVisited);
        maxVal += temp;
    }

    return maxVal + 1;
}

/*
* 
* 邻接矩阵做法：
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int vertexCount;

int dfs(int startVertexId, vector<bool>& isVisited, vector< vector<bool> >& matrix);
int main()
{
    int n;
    cin >> n;

    vertexCount = n;

    vector< vector<bool> > matrix(vertexCount, vector<bool>(vertexCount, false));

    //顶点访问标记
    vector<bool> isVisited(vertexCount, false);

    for (int i = 0; i < vertexCount - 1; i++) {

        int node1, node2;
        cin >> node1 >> node2;
        node1--;
        node2--;

        matrix[node1][node2] = true;
        matrix[node2][node1] = true;
    }

    //遍历根节点的子节点, 看哪个节点个数最多
    isVisited[0] = true;    //根节点已经访问过
    int maxVal = 0;
    for (int i = 0; i < vertexCount; i++) {

        //如果和当前顶点有通路, 并且没有被访问过, 则访问它
        if (matrix[0][i] == true) {
            int temp = dfs(i, isVisited, matrix);
            maxVal = max(temp, maxVal);
        }
    }

    cout << maxVal << endl;

    return 0;
}

//返回当前这个树的节点个数
int dfs(int startVertexId, vector<bool>& isVisited, vector< vector<bool> >& matrix)
{
    if (isVisited[startVertexId] == true) {
        return 0;
    }

    isVisited[startVertexId] = true;             //标记该顶点已经被访问过

    int maxVal = 0;
    for (int i = 0; i < vertexCount; i++) {

        //如果和当前顶点有通路, 并且没有被访问过, 则访问它
        if (matrix[startVertexId][i] == true) {
            int temp = dfs(i, isVisited, matrix);
            maxVal += temp;
        }
    }

    return maxVal + 1;
}

*/