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

class CBTInserter {
private:
    TreeNode* root;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
    }

    int insert(int val) {

        queue<TreeNode *> que;

        if (root != nullptr) {
            que.push(root);
        }

        while (que.empty() == false) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left == nullptr) {
                    node->left = new TreeNode(val, nullptr, nullptr);
                    return node->val;
                }
                if (node->right == nullptr) {
                    node->right = new TreeNode(val, nullptr, nullptr);
                    return node->val;
                }

                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }

        return val;
    }

    TreeNode* get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */

int main()
{

}
