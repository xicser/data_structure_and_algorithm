#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int val;
    int index;
    Node(int v, int i) {
        val = v;
        index = i;
    }
};

struct cmp
{
    bool operator() (const Node& n1, const Node& n2)
    {
        if (n1.val != n2.val) {
            return n1.val > n2.val;
        }
        else {
            return n1.index > n2.index;
        }
    }
};

int main()
{
    int n;
    priority_queue<Node, vector<Node>, cmp> que;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmpVal;
        cin >> tmpVal;
        que.push(Node(tmpVal, i));
    }

    int sum = 0;
    while (que.empty() == false) {

        Node node1 = que.top();
        que.pop();

        if (que.empty() == false) {

            Node node2 = que.top();

            if (node1.val != node2.val) {
                continue;
            }

            //值相等, 且相邻
            if (node1.val == node2.val && abs(node1.index - node2.index) == 1) {
                que.pop();
                Node nodeNew(node1.val + 1, max(node1.index, node2.index));
                que.push(nodeNew);

                sum++;
            }

        }
        else {
            break;
        }

    }

    cout << sum << endl;

    return 0;
}
