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
    int getMinimumDifference(TreeNode* root) {
        process(root);

        int result = 99999999;
        for (unsigned int i = 1; i < nums.size(); i++) {
            result = min(result, nums[i] - nums[i - 1]);
        }

        return result;
    }

private:
    void process(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        process(root->left);
        nums.push_back(root->val);
        process(root->right);
    }

    vector<int> nums;
};

int main()
{

    return 0;
}
