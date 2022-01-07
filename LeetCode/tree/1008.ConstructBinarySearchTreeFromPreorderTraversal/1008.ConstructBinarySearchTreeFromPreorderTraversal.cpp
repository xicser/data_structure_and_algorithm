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
private:
    //从左往右找到第一个比val大的数的下标
    int findFirstBigIndex(vector<int>& preorder, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (preorder[i] > val) {
                return i;
            }
        }

        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, int start, int end) {

        if (start > end) {
            return nullptr;
        }
        if (start == end) {
            return new TreeNode(preorder[start], nullptr, nullptr);
        }

        int val = preorder[start];
        TreeNode* root = new TreeNode(val);

        int index = findFirstBigIndex(preorder, start + 1, end, val);
        if (index != -1) {
            root->left = buildTree(preorder, start + 1, index - 1);
            root->right = buildTree(preorder, index, end);
        }
        else {
            //== -1 表示右子树为空
            root->left = buildTree(preorder, start + 1, end);
            root->right = nullptr;
        }

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, 0, preorder.size() - 1);
    }
};

int main()
{
    vector<int> preorder = {4, 2};
    Solution sol;
    sol.bstFromPreorder(preorder);

}
