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

struct TreeInfo {
    bool isBlance;
    int height;
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {

        TreeInfo info = getInfo(root);
        return info.isBlance;
    }

private:
    TreeInfo getInfo(TreeNode* root) {

        TreeInfo nowTree;
        if (root == nullptr) {
            nowTree.height = 0;
            nowTree.isBlance = true;
            return nowTree;
        }

        TreeInfo left = getInfo(root->left);
        TreeInfo right = getInfo(root->right);

        nowTree.height = max(left.height, right.height) + 1;
        if (abs(left.height - right.height) <= 1 && left.isBlance == true && right.isBlance == true) {
            nowTree.isBlance = true;
        }
        else {
            nowTree.isBlance = false;
        }

        return nowTree;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
