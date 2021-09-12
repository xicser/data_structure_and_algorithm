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
    vector<int> preorderTraversal(TreeNode* root) {
        process(root);
        return result;
    }

private:
    void process(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        result.push_back(root->val);
        process(root->left);
        process(root->right);
    }

    vector<int> result;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
