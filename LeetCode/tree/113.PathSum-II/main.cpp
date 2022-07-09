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
    vector< vector<int> > pathSum(TreeNode* root, int targetSum) {

        if (root == nullptr) {
            return {};
        }

        this->targetSum = targetSum;

        vector<int> path;
        int sum = 0;
        dfs(root, path, sum);

        return paths;
    }

private:
    void dfs(TreeNode* root, vector<int> path, int sum) {

        sum += root->val;
        path.push_back(root->val);

        //到了叶子节点
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == this->targetSum) {
                paths.push_back(path);
            }
            return;
        }

        if (root->left != nullptr) {
            dfs(root->left, path, sum);
        }
        if (root->right != nullptr) {
            dfs(root->right, path, sum);
        }
    }

    vector< vector<int> > paths;
    int targetSum;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
