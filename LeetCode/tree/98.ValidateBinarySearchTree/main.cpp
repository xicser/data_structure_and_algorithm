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
    bool isValidBST(TreeNode* root) {

        process(root);

        for (unsigned int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }

        return true;
    }

    void process(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        process(root->left);
        nums.push_back(root->val);
        process(root->right);
    }

private:
    vector<int> nums;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
