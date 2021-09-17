#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    //�ݹ麬��: ��root���в���p, q,
    //�������p����q, �Ͱ�q����p����, ����ֵ��Ϊ��, ��˵���ҵ���q����p
    //����ֵΪ��, ��˵��û�ҵ�p����q
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //p, q�ֱ�������������
        if (left != nullptr && right != nullptr) {
            return root;
        }
        //p, q������������
        else if (left == nullptr && right != nullptr) {
            return right;
        }
        //p, q������������
        else { //left != nullptr && right == nullptr
            return left;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
