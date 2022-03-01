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
// 1 2 3 4 5 6 7
class Solution {
private:
    vector<TreeNode*> buildTree(int start, int end) {

        if (start > end) {
            return { nullptr };
        }

        if (end == start) {
            return { new TreeNode(start, nullptr, nullptr) };
        }

        vector<TreeNode*> result;
        for (int pos = start; pos <= end; pos++) {

            vector<TreeNode*> resultLeft = buildTree(start, pos - 1);
            vector<TreeNode*> resultRight = buildTree(pos + 1, end);

            //构造
            for (auto treeLeft : resultLeft) {
                for (auto treeRight : resultRight) {
                    TreeNode* root = new TreeNode(pos);
                    root->left = treeLeft;
                    root->right = treeRight;

                    result.push_back(root);
                }
            }
        }

        return result;
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
    vector<TreeNode*> result = sol.generateTrees(9);
    for (int i = 0; i < result.size(); i++) {
        sol.printTree(result[i]);
        cout << endl;
    }
}
