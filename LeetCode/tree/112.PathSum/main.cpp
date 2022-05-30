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
    bool hasPathSum(TreeNode* root, int targetSum) {

        if (root == nullptr) {
            return false;
        }

        this->targetSum = targetSum;
        hasPath = false;
        process(root, 0);

        return hasPath;
    }

    void process(TreeNode* root, int sum) {

        if (hasPath == true) {
            return;
        }

        int val = root->val;
        sum += val;

        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                hasPath = true;
                return;
            }
        }

        if (root->left != nullptr) {
            process(root->left, sum);
        }
        if (root->right != nullptr) {
            process(root->right, sum);
        }
    }

private:
    int targetSum;
    bool hasPath;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
