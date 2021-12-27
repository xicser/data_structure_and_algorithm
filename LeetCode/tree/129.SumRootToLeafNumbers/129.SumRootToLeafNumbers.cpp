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
    int sumNumbers(TreeNode* root) {

        backtraking(root);
        int result = 0;

        for (int pathSum : resultPath) {
            result += pathSum;
        }

        return result;
    }

private:
    vector<int> resultPath;
    string path;
    void backtraking(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            
            path.push_back(root->val + 48);
            
            int pathSum = atoi(path.c_str());
            //cout << pathSum << endl;
            resultPath.push_back(pathSum);
            
            path.pop_back();
            return;
        }

        char val = root->val + 48;

        //回溯的流程
        path.push_back(val);
        backtraking(root->left);
        path.pop_back();

        path.push_back(val);
        backtraking(root->right);
        path.pop_back();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
