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

        process(root);

        for (unsigned int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }

        return true;
    }

    void process(TreeNode* root) {

        if (root == nullptr) {
            return;
        }

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
                printf("%d ", pCur->val);
                nums.push_back(pCur->val);
                pCur = pCur->right;
            }
        }
    }

private:
    vector<int> nums;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
