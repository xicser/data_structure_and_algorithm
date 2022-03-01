#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //递归含义：使用n个节点，构造所有可能的满二叉树, 返回所有树的根节点
    vector<TreeNode*> allPossibleFBT(int n) {

        if (n % 2 == 0) {
            return { };
        }
        if (n == 1) {
            return { new TreeNode(0, nullptr, nullptr) };
        }

        vector<TreeNode*> result;
        int leftNodeCnt = 1;
        while (leftNodeCnt <= n - 2) {
            int rightNodeCnt = n - 1 - leftNodeCnt;

            vector<TreeNode*> leftTrees = allPossibleFBT(leftNodeCnt);
            vector<TreeNode*> rightTrees = allPossibleFBT(rightNodeCnt);

            for (TreeNode* treeLeft : leftTrees) {
                for (TreeNode* treeRight : rightTrees) {
                    TreeNode* node = new TreeNode(0);
                    node->left = treeLeft;
                    node->right = treeRight;

                    result.push_back(node);
                }
            }

            leftNodeCnt += 2;
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
