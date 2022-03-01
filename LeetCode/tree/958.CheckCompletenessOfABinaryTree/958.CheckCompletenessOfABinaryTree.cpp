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
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);

        vector<TreeNode*> vec;
        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                vec.push_back(node);

                //层序遍历的时候, 把空节点也算进去
                if (node) {
                    que.push(node->left);
                    que.push(node->right);
                }
            }
        }

        for (int i = 0; i < vec.size(); i++) {
            TreeNode* node = vec[i];
            if (node == nullptr) {
                for (int j = i + 1; j < vec.size(); j++) {
                    TreeNode* node = vec[j];
                    if (node != nullptr) {
                        return false;
                    }
                }
                break;
            }
        }

        return true;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
