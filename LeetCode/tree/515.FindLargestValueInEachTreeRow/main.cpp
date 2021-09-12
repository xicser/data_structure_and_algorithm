#include <iostream>
#include <vector>
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode *> que;
        if (root != NULL) que.push(root);
        vector < int > result;

        while (!que.empty()) {
            int size = que.size();

            int maxValue = que.front()->val;
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                maxValue = max(maxValue, node->val);

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(maxValue);
        }

        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
