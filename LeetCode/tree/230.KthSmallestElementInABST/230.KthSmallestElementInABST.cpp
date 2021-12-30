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
    vector<int> vals;
    void inOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        inOrder(root->left);
        vals.push_back(root->val);
        inOrder(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);

        return vals[k - 1];
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
