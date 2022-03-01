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
        processDelete(root, key);
        return root;
    }

private:

    //寻找中序遍历中, node节点的前一个元素
    TreeNode* findInorderPrevNode(TreeNode* node) {
        TreeNode* pCur = node;
        while (1) {
            if (pCur->right == nullptr) {
                break;
            }
            pCur = pCur->right;
        }

        return pCur;
    }

    //寻找中序遍历中, node节点的后一个元素
    TreeNode* findInorderNextNode(TreeNode* node) {
        TreeNode* pCur = node;
        while (1) {
            if (pCur->left == nullptr) {
                break;
            }
            pCur = pCur->left;
        }

        return pCur;
    }

    void processDelete(TreeNode*& root, int val) {

        //待删除的元素不存在
        if (root == nullptr) {
            return;
        }

        //找到了
        if (root->val == val) {

            //叶子节点, 可以直接删
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                root = nullptr;
            }
            else if (root->left != nullptr) {
                TreeNode* prev = findInorderPrevNode(root->left);
                root->val = prev->val;
                processDelete(root->left, prev->val);
            }
            else {
                TreeNode* next = findInorderNextNode(root->right);
                root->val = next->val;
                processDelete(root->right, next->val);
            }
        }
        else if (root->val > val) {
            processDelete(root->left, val);
        }
        else {
            processDelete(root->right, val);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
