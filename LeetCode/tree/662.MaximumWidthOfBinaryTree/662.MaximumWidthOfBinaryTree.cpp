#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

typedef unsigned long long integer;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        integer maxWidth = 0;
        queue< pair<TreeNode*, integer> > que;

        que.push(pair<TreeNode*, integer>(root, 1)); // 从1开始编号

        while (que.empty() == false) {

            integer size = que.size();
            integer minIndex = 0;
            integer maxIndex = 0;
            for (integer i = 0; i < size; i++) {

                TreeNode* node = que.front().first;
                integer index = que.front().second;

                if (i == 0) {
                    minIndex = index;
                }
                if (i == size - 1) {
                    maxIndex = index;
                }

                que.pop();

                if (node->left != nullptr) {
                    que.push(pair<TreeNode*, integer>(node->left, index * 2));
                }
                if (node->right != nullptr) {
                    que.push(pair<TreeNode*, integer>(node->right, index * 2 + 1));
                }
            }

            maxWidth = max(maxWidth, maxIndex - minIndex + 1);
        }

        return maxWidth;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
