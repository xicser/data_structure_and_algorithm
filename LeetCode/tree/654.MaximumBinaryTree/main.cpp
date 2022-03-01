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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return process(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* process(vector<int>& nums, int left, int right) {

        if (left > right) {
            return nullptr;
        }

        if (left == right) {
            return new TreeNode(nums[left], nullptr, nullptr);
        }

        int maxIndex = findMaxNumIndex(nums, left, right);

        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = process(nums, left, maxIndex - 1);
        root->right = process(nums, maxIndex + 1, right);

        return root;
    }

    int findMaxNumIndex(vector<int>& nums, int left, int right) {

        int maxVal = INT_MIN;
        int index;
        for (int i = left; i <= right; i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                index = i;
            }
        }

        return index;
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
    vector<int> nums = {3,2,1};
    Solution sol;
    TreeNode* root = sol.constructMaximumBinaryTree(nums);

    traverse(root);


    return 0;
}
