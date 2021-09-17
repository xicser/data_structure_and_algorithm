#include <iostream>

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        process(root, key);
        return root;
    }

private:

    //找到root树中, 中序遍历下根节点在的前驱
    TreeNode* findPrev(TreeNode* root) {
        TreeNode* node = root->left;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    //找到root树中, 中序遍历下根节点在的后继
    TreeNode* findNext(TreeNode* root) {
        TreeNode* node = root->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void process(TreeNode*& root, int val) {

        //待删除的节点不存在
        if (root == nullptr) {
            return;
        }

        //找到了
        if (root->val == val) {

            //如果是叶子节点
            if (root->left == nullptr && root->right == nullptr) {
                //直接删
                delete root;
                root = nullptr;
            }
            //左子树不为空
            else if (root->left != nullptr) {
                TreeNode* prev = findPrev(root);
                root->val = prev->val;

                //在左子树中删除prev节点
                process(root->left, prev->val);
            }
            //右子树不为空
            else {
                TreeNode* next = findNext(root);
                root->val = next->val;

                //在右子树中删除next节点
                process(root->right, next->val);
            }
        }
        else if (root->val > val) {
            process(root->left, val);
        }
        else {
            process(root->right, val);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
