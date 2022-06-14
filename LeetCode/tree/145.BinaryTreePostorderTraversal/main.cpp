#include <iostream>
#include <stack>
#include <algorithm>
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

//class Solution {
//public:
//    vector<int> postorderTraversal(TreeNode* root) {
//        process(root);
//        return result;
//    }
//
//private:
//    void process(TreeNode* root) {
//
//        if (root == nullptr) {
//            return;
//        }
//
//        process(root->left);
//        process(root->right);
//        result.push_back(root->val);
//    }
//
//    vector<int> result;
//};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        if (root == nullptr) {
            return { };
        }

        vector<int> result;
        stack<TreeNode *> stk;

        stk.push(root);

        while (stk.empty() == false) {

            TreeNode* node = stk.top();
            result.push_back(node->val);
            stk.pop();

            if (node->left != nullptr) {
                stk.push(node->left);
            }
            if (node->right != nullptr) {
                stk.push(node->right);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
