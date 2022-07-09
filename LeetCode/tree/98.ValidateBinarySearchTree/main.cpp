#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

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
    bool isValidBST(TreeNode* root) {

        if (root == nullptr) {
            return true;
        }

        long long last = LONG_MIN;
        stack<TreeNode* > stk;
        TreeNode* pCur = root;
        while (pCur || !stk.empty()) {
            if (pCur) {
                stk.push(pCur);
                pCur = pCur->left;
            }
            else {
                pCur = stk.top();
                stk.pop();

                if (pCur->val <= last) {
                    return false;
                }
                else {
                    last = pCur->val;
                }

                pCur = pCur->right;
            }
        }

        return true;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
