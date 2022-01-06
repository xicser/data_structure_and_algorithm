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
    //寻找val在array中的位置
    int findPos(vector<int>& array, int val) {
        for (int i = 0; i < array.size(); i++) {
            if (array[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& postorder, int postStart, int postEnd) {

        if (preStart == preEnd) {
            return new TreeNode(preorder[preStart], nullptr, nullptr);
        }
        if (preStart > preEnd) {
            return nullptr;
        }

        int rootVal = preorder[preStart];
        int rootNextVal = preorder[preStart + 1];

        //寻找根节点下一个元素在后序遍历序列里的位置
        int pos = findPos(postorder, rootNextVal);
        int len = pos - postStart + 1;

        TreeNode* root = new TreeNode(rootVal);

        //构造左子树
        root->left = buildTree(preorder, preStart + 1, preStart + len,
                               postorder, postStart, pos);

        //构造右子树
        root->right = buildTree(preorder, preStart + len + 1, preEnd,
                                postorder, postStart + len, postEnd - 1);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return buildTree(preorder, 0, preorder.size() - 1,
                         postorder, 0, postorder.size() - 1);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
