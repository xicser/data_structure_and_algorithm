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

//preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder) {

        if (preorder.size() == 0) {
            return nullptr;
        }
        if (preorder.size() == 1) {
            return new TreeNode(preorder[0], nullptr, nullptr);
        }

        int rootVal = preorder[0];
        int rootNextVal = preorder[1];

        //寻找根节点下一个元素在后序遍历序列里的位置
        int pos = findPos(postorder, rootNextVal);

        TreeNode* root = new TreeNode(rootVal);

        //切割先序
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + pos + 1);
        vector<int> rightPre(preorder.begin() + 1 + pos + 1, preorder.end());

        //切割后序
        vector<int> leftPost(postorder.begin(), postorder.begin() + pos + 1);
        vector<int> rightPost(postorder.begin() + pos + 1, postorder.end() - 1);

        //构造左子树
        root->left = buildTree(leftPre, leftPost);

        //构造右子树
        root->right = buildTree(rightPre, rightPost);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return buildTree(preorder, postorder);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
