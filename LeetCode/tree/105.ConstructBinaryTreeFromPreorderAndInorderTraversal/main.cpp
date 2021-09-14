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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inSize = inorder.size();
        int preSize = preorder.size();

        if (inSize == 0 || preSize == 0) {
            return nullptr;
        }
        if (inSize == 1 || preSize == 1) {
            TreeNode *root = new TreeNode(inorder[0]);
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }

        int preFirst = preorder[0];
        int rootIndex = findElemtIndex(inorder, preFirst);

        //切割中序数组
        vector<int> inArrayLeft(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> inArrayRight(inorder.begin() + rootIndex + 1, inorder.end());

        //切割先序数组
        vector<int> preArrayLeft(preorder.begin() + 1, preorder.begin() + 1 + inArrayLeft.size());
        vector<int> preArrayRight(preorder.begin() + 1 + inArrayLeft.size(), preorder.end());

        //创建根节点
        TreeNode *root = new TreeNode(inorder[rootIndex]);
        root->left = buildTree(preArrayLeft, inArrayLeft);
        root->right = buildTree(preArrayRight, inArrayRight);

        return root;
    }

private:
    //查找val在数组array中的下标
    int findElemtIndex(vector<int>& array, int val) {

        for (unsigned int i = 0; i < array.size(); i++) {
            if (array[i] == val) {
                return i;
            }
        }

        return array[array.size() - 1];
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
