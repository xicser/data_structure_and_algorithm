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
    queue<TreeNode *> que;
    TreeNode* root;
public:
    CBTInserter(TreeNode* root) {

        this->root = root;
        if (root != nullptr) que.push(root);

        while (!que.empty()) {

            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();

                //找到了第一个可以插入的位置(父节点)
                if (node->left == nullptr || node->right == nullptr) {
                    return;
                }

                que.pop();

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
    }

    int insert(int val) {

        TreeNode* nodeNew = new TreeNode(val, nullptr, nullptr);
        TreeNode* nodeParent = que.front();

        if (nodeParent->left == nullptr) {
            nodeParent->left = nodeNew;
        }
        else if (nodeParent->right == nullptr) {
            nodeParent->right = nodeNew;
        }

        //继续层序遍历的流程，找到下一个可以插入的位置(父节点)
        while (!que.empty()) {

            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();

                if (node->left == nullptr || node->right == nullptr) {
                    return nodeParent->val;
                }

                que.pop();

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return nodeParent->val;
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
