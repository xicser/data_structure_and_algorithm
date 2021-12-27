#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        if (root != NULL) que.push(root);
        vector < vector<int> > result;
        bool dir = true;  //true表示从左往右
        while (!que.empty()) {
            int size = que.size();
            vector<int> vec;

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            if (dir == false) {
                reverse(vec.begin(), vec.end());
                dir = true;
            }
            else {
                dir = false;
            }
            result.push_back(vec);
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
