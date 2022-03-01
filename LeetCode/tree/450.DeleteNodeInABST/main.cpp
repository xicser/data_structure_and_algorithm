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

    //Ѱ�����������, node�ڵ��ǰһ��Ԫ��
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

    //Ѱ�����������, node�ڵ�ĺ�һ��Ԫ��
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

        //��ɾ����Ԫ�ز�����
        if (root == nullptr) {
            return;
        }

        //�ҵ���
        if (root->val == val) {

            //Ҷ�ӽڵ�, ����ֱ��ɾ
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
