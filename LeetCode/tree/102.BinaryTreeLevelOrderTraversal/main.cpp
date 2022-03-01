#include <iostream>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        if (root != nullptr) {
            que.push(root);
        }

        while (que.empty() == false) {

            int size = que.size();
            vector<int> vecLevel;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vecLevel.push_back(node->val);

                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }

            result.push_back(vecLevel);
        }

        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
