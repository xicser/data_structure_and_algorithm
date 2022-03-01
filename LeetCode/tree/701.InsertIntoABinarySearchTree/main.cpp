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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        process(root, val);
        return root;
    }

private:
    void process(TreeNode*& root, int val) {

        //指针为空的位置, 恰好就是要插入的位置
        if (root == nullptr) {
            root = new TreeNode(val);
            return;
        }

        if (root->val > val) {
            process(root->left, val);
        }
        else {
            process(root->right, val);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
