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

        this->targetSum = targetSum;

        vector<int> path;
        int sum;
        process(root, path, sum);
        return paths;
    }

private:
    void process(TreeNode* root, vector<int> path, int sum) {

        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {

            path.push_back(root->val);
            sum += root->val;

            if (sum == this->targetSum) {
                paths.push_back(path);
            }

            return;
        }

        path.push_back(root->val);
        sum += root->val;
        process(root->left, path, sum);
        process(root->right, path, sum);
    }

    vector< vector<int> > paths;
    int targetSum;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
