#include <iostream>
#include <vector>
#include <string>

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

        result = 0;
        process(root, "");
        return result;
    }

private:
    int result;
    void process(TreeNode* root, string path) {

        if (root == nullptr) {
            return;
        }

        //只有在叶子节点的地方收集结果
        if (root->left == nullptr && root->right == nullptr) {
            string strNum = to_string(root->val);
            path += strNum;
            // cout << path << endl;
            result += atoi(path.c_str());
            return;
        }

        string strNum = to_string(root->val);
        process(root->left, path + strNum);
        process(root->right, path + strNum);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
