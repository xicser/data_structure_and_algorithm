#include <iostream>
#include <stack>
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
    vector<int> preorderTraversal(TreeNode* root) {

        if (root == nullptr) {
            return {};
        }
        vector<int> result;
        stack<TreeNode*> stk;

        TreeNode* pCur = root;
        stk.push(pCur);

        while (stk.empty() == false) {
            pCur = stk.top();
            result.push_back(pCur->val);
            stk.pop();

            if (pCur->right != nullptr) {
                stk.push(pCur->right);
            }
            if (pCur->left != nullptr) {
                stk.push(pCur->left);
            }
        }

        return result;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
