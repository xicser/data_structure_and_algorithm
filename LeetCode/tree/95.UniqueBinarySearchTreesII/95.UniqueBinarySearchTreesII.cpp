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
private:
    //函数含义：获取区间[start, end]之间，能构成二叉搜索树的集合
    vector<TreeNode*> buildTree(int start, int end) {

        if (start > end) {
            return { nullptr };
        }
        if (start == end) {
            TreeNode* rootNode = new TreeNode(start);
            rootNode->left = rootNode->right = nullptr;
            return { rootNode };
        }

        vector<TreeNode*> resultTrees;
        for (int pos = start; pos <= end; pos++) {
            vector<TreeNode*> leftTrees = buildTree(start, pos - 1);   //获取左侧子区间的树
            vector<TreeNode*> rightTrees = buildTree(pos + 1, end);    //获取右侧子区间的树

            //两两相乘获取所有的结果
            for (int i = 0; i < leftTrees.size(); i++) {
                for (int j = 0; j < rightTrees.size(); j++) {
                    TreeNode* rootNode = new TreeNode(pos);
                    rootNode->left = leftTrees[i];
                    rootNode->right = rightTrees[j];
                    resultTrees.push_back(rootNode);
                }
            }
        }

        return resultTrees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1, n);
    }

    void printTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
};

int main()
{
    Solution sol;
    vector<TreeNode*> result = sol.generateTrees(3);
    for (int i = 0; i < result.size(); i++) {
        sol.printTree(result[i]);
        cout << endl;
    }
}
