#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (preorder.size() == 0) {
            return nullptr;
        }
        if (preorder.size() == 1) {
            return new TreeNode(preorder[0], nullptr, nullptr);
        }

        int pre = preorder[0];
        int index = findElemInOrder(inorder, pre);

        TreeNode* root = new TreeNode(pre);

        //切割先序
        vector<int> preLeft(preorder.begin() + 1, preorder.begin() + index + 1);
        vector<int> preRight(preorder.begin() + index + 1, preorder.end());

        //切割中序
        vector<int> inLeft(inorder.begin(), inorder.begin() + index);
        vector<int> inRight(inorder.begin() + index + 1, inorder.end());

        root->left = buildTree(preLeft, inLeft);
        root->right = buildTree(preRight, inRight);

        return root;
    }

private:
    //在inorder中查找val的位置
    int findElemInOrder(vector<int>& inorder, int val) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == val) {
                return i;
            }
        }

        return -1;
    }
};

void traverse(TreeNode *root)
{
    if (root == nullptr) {
        return;
    }

    printf("%d ", root->val);
    traverse(root->left);
    traverse(root->right);
}

int main()
{
    Solution sol;

    vector<int> preorder1 = {3,9,20,15,7};
    vector<int> inorder1 = {9,3,15,20,7};
    TreeNode *tree1 = sol.buildTree(preorder1, inorder1);
    traverse(tree1);
    printf("\n");

//    vector<int> inorder2 = {9,3,15,20,7};
//    vector<int> postorder2 = {9,15,7,20,3};
//    TreeNode *tree2 = sol.buildTree(inorder2, postorder2);
//    traverse(tree2);

    return 0;
}
