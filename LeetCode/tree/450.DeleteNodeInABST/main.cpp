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

    //�ҵ�root����, ��������¸��ڵ��ڵ�ǰ��
    TreeNode* findPrev(TreeNode* root) {
        TreeNode* node = root->left;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    //�ҵ�root����, ��������¸��ڵ��ڵĺ��
    TreeNode* findNext(TreeNode* root) {
        TreeNode* node = root->right;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void process(TreeNode*& root, int val) {

        //��ɾ���Ľڵ㲻����
        if (root == nullptr) {
            return;
        }

        //�ҵ���
        if (root->val == val) {

            //�����Ҷ�ӽڵ�
            if (root->left == nullptr && root->right == nullptr) {
                //ֱ��ɾ
                delete root;
                root = nullptr;
            }
            //��������Ϊ��
            else if (root->left != nullptr) {
                TreeNode* prev = findPrev(root);
                root->val = prev->val;

                //����������ɾ��prev�ڵ�
                process(root->left, prev->val);
            }
            //��������Ϊ��
            else {
                TreeNode* next = findNext(root);
                root->val = next->val;

                //����������ɾ��next�ڵ�
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
