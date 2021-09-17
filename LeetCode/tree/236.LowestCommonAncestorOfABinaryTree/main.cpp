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

    //递归含义: 在root树中查找p, q,
    //如果遇到p或者q, 就把q或者p返回, 返回值不为空, 就说明找到了q或者p
    //返回值为空, 就说明没找到p或者q
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr) {
            return nullptr;
        }

        if (root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //p, q分别在左右子树中
        if (left != nullptr && right != nullptr) {
            return root;
        }
        //p, q都在右子树中
        else if (left == nullptr && right != nullptr) {
            return right;
        }
        //p, q都在左子树中
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
