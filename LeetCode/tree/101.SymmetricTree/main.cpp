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
    bool compare(TreeNode* left, TreeNode* right) {

        //�����ų��սڵ�����
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        // �ų��˿սڵ�, ���ų���ֵ����ͬ�����
        else if (left->val != right->val) return false;

        //��ʱ����: ���ҽڵ㶼��Ϊ��, ����ֵ��ͬ�����
        //��ʱ�����ݹ�, ����һ����ж�
        bool outside = compare(left->left, right->right);   // ��������������������
        bool inside = compare(left->right, right->left);    // ���������ҡ�����������
        bool isSame = outside && inside;                    // ���������С����������У��߼�����
        return isSame;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
