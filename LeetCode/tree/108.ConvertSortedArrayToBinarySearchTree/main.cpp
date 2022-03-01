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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = process(nums, 0, nums.size() - 1);
        return root;
    }

private:
    TreeNode* process(vector<int>& nums, int s, int e) {

        if (s > e) {
            return nullptr;
        }

        int mid = s + (e - s) / 2;

        //创建根节点
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = process(nums, s, mid - 1);
        root->right = process(nums, mid + 1, e);

        return root;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
