#include <iostream>
#include <map>

using namespace std;


/* ���鼯ʵ�� */
class UnionFindSet {

public:
    UnionFindSet(int n) {

        this->n = n;
        this->father = new int[this->n];

        //��ʼ�����鼯����
        for (int i = 1; i < this->n; i++) {
            father[i] = i;      //��ʼʱ, ÿ������ֻ��һ���ڵ�
        }
    }
    ~UnionFindSet() {
        delete []father;
    }

    //��node1��node2���ڵ��������Ϻϲ�
    void unionSet(int node1, int node2) {
        int root1 = findRoot(node1);
        int root2 = findRoot(node2);
        if (root1 == root2) {
            return;
        }

        //�ϲ�
        father[root1] = root2;
    }

    //�ж������ڵ��Ƿ�����ͬһ������
    bool isSameSet(int node1, int node2) {
        int root1 = findRoot(node1);
        int root2 = findRoot(node2);

        return root1 == root2;
    }

    //Ѱ�Ҹ��ڵ����
    int findRoot(int node) {
        while (node != father[node]) {
            node = father[node];
        }
        return node;
    }

    //Ѱ�Ҹ��ڵ�ݹ�
    int findRootR(int node) {
        if (father[node] == node) {
            return node;
        }

        return findRootR(father[node]);
    }

    //Ѱ�Ҹ��ڵ��Ż�
    int findRootOptimize(int node) {

        int nodeOrigin = node;

        while (node != father[node]) {
            node = father[node];
        }

        //·���Ż�
        while (nodeOrigin != father[nodeOrigin]) {

            int tmp = father[nodeOrigin];       //�Ȱ�ԭ���İְּ�����
            father[nodeOrigin] = node;          //�������ϸ��°ְ�

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
