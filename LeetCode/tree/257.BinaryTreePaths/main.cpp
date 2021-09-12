#include <iostream>
#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        process(root, path);
        return vec;
    }

    void process(TreeNode* root, string path) {

        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            path += (to_string(root->val));
            vec.push_back(path);
            return;
        }

        path += (to_string(root->val) + "->" );

        process(root->left, path);
        process(root->right, path);
    }

private:
    vector< string > vec;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
