#include <iostream>
#include <map>

using namespace std;


/* 并查集实现 */
class UnionFindSet {

public:
    UnionFindSet(int n) {

        this->n = n;
        this->father = new int[this->n];

        //初始化并查集数组
        for (int i = 1; i < this->n; i++) {
            father[i] = i;      //初始时, 每个集合只有一个节点
        }
    }
    ~UnionFindSet() {
        delete []father;
    }

    //把node1和node2所在的两个集合合并
    void unionSet(int node1, int node2) {
        int root1 = findRoot(node1);
        int root2 = findRoot(node2);
        if (root1 == root2) {
            return;
        }

        //合并
        father[root1] = root2;
    }

    //判断两个节点是否属于同一个集合
    bool isSameSet(int node1, int node2) {
        int root1 = findRoot(node1);
        int root2 = findRoot(node2);

        return root1 == root2;
    }

    //寻找根节点递推
    int findRoot(int node) {
        while (node != father[node]) {
            node = father[node];
        }
        return node;
    }

    //寻找根节点递归
    int findRootR(int node) {
        if (father[node] == node) {
            return node;
        }

        return findRootR(father[node]);
    }

    //寻找根节点优化
    int findRootOptimize(int node) {

        int nodeOrigin = node;

        while (node != father[node]) {
            node = father[node];
        }

        //路径优化
        while (nodeOrigin != father[nodeOrigin]) {

            int tmp = father[nodeOrigin];       //先把原来的爸爸记下来
            father[nodeOrigin] = node;          //再让它认个新爸爸

            nodeOrigin = tmp;
        }

        return node;
    }

private:
    int n;
    int *father;
};

int main()
{
    UnionFindSet ufs(100);

    cout << ufs.findRootR(10) << endl;

    ufs.unionSet(10, 20);

    cout << ufs.findRoot(10) << endl;
    cout << ufs.findRootOptimize(10) << endl;


    return 0;
}
