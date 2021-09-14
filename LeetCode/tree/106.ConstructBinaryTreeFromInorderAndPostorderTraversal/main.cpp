#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int inSize = inorder.size();
        int postSize = postorder.size();

        if (inSize == 0 || postSize == 0) {
            return nullptr;
        }
        if (inSize == 1 || postSize == 1) {
            TreeNode *root = new TreeNode(inorder[0]);
            root->left = nullptr;
            root->right = nullptr;
            return root;
        }

        int postLast = postorder[postSize - 1];
        int rootIndex = findElemtIndex(inorder, postLast);

        //切割中序数组
        vector<int> inArrayLeft(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> inArrayRight(inorder.begin() + rootIndex + 1, inorder.end());

        //切割后序数组
        vector<int> postArrayLeft(postorder.begin(), postorder.begin() + inArrayLeft.size());
        vector<int> postArrayRight(postorder.begin() + inArrayLeft.size(), postorder.end() - 1);
//        for (int i = 0; i < postSize - 1; i++) {
//            if (isLeft(postorder[i], rootIndex, inorder) == true) {
//                postArrayLeft.push_back(postorder[i]);
//            }
//            else {
//                postArrayRight.push_back(postorder[i]);
//            }
//        }

        //创建根节点
        TreeNode *root = new TreeNode(inorder[rootIndex]);
        root->left = buildTree(inArrayLeft, postArrayLeft);
        root->right = buildTree(inArrayRight, postArrayRight);

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

    //判断elemt是不是在array数组index下标的左边
    bool isLeft(int elemt, int index, vector<int>& array) {

        for (int i = 0; i < index; i++) {
            if (elemt == array[i]) {
                return true;
            }
        }

        return false;
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

    vector<int> inorder1 = {2, 1};
    vector<int> postorder1 = {2, 1};
    TreeNode *tree1 = sol.buildTree(inorder1, postorder1);
    traverse(tree1);
    printf("\n");

    vector<int> inorder2 = {9,3,15,20,7};
    vector<int> postorder2 = {9,15,7,20,3};
    TreeNode *tree2 = sol.buildTree(inorder2, postorder2);
    traverse(tree2);

    return 0;
}
