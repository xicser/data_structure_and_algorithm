#include <iostream>
#include <cmath>
#include <math.h>

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
private:
    int farest;
    int getTreeHight(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        int left = getTreeHight(root->left);
        int right = getTreeHight(root->right);
        int hight = max(left, right) + 1;

        farest = max(farest, left + right);

        return hight;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        farest = -1; 
        getTreeHight(root);
        return farest;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
