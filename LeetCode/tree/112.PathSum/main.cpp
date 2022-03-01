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
        this->targetSum = targetSum;
        hasPath = false;
        int sum = 0;
        process(root, sum);

        return hasPath;
    }

    void process(TreeNode* root, int sum) {

        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            if (sum == this->targetSum) {
                hasPath = true;
            }
            return;
        }

        sum += root->val;
        process(root->left, sum);
        process(root->right, sum);
    }

private:
    vector<int> pathSums;
    int targetSum;
    bool hasPath;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
