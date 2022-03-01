#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> result;

        stack<TreeNode*> stk;
        TreeNode* pCur = root;

        while (pCur != nullptr || stk.empty() == false) {

            if (pCur != nullptr) {
                stk.push(pCur);
                pCur = pCur->left;
            }
            else {
                TreeNode* node = stk.top();
                stk.pop();
                result.push_back(node->val);
                pCur = node->right;
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
