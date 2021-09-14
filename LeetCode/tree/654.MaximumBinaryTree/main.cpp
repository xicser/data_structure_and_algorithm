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

    TreeNode* process(vector<int>& nums, int s, int e) {

        if (e < s) {
            return nullptr;
        }

        int maxIndex = findMaxIndex(nums, s, e);

        TreeNode* root = new TreeNode(nums[maxIndex]);

        root->left = process(nums, s, maxIndex - 1);
        root->right = process(nums, maxIndex + 1, e);

        return root;
    }


    int findMaxIndex(vector<int>& nums, int start, int end) {

        int max = nums[start];
        int index = start;
        for (int i = start + 1; i <= end; i++) {
            if (max < nums[i]) {
                max = nums[i];
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
    vector<int> nums = {3,2,1,6,0,5};
    Solution sol;
    TreeNode* root = sol.constructMaximumBinaryTree(nums);

    traverse(root);


    return 0;
}
