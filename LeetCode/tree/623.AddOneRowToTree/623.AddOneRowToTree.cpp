#include <iostream>
#include <vector>
#include <queue>

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
    //获取二叉树第depth层上的节点
    vector<TreeNode *> getLevelNodes(TreeNode* root, int depth) {
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        vector < TreeNode* > result;

        int depthCnt = 1;
        while (!que.empty()) {
            int size = que.size();

            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                
                if (depthCnt == depth) {
                    result.push_back(node);
                }

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            depthCnt++;

            if (result.size() != 0) {
                break;
            }
        }

        return result;
    }

public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            newNode->right = nullptr;
            return newNode;
        }

        vector<TreeNode*> nodes = getLevelNodes(root, depth - 1);

        for (int i = 0; i < nodes.size(); i++) {
            TreeNode* node = nodes[i];
            TreeNode* oldLeft = node->left;
            TreeNode* oldRight = node->right;

            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);

            node->left = newLeft;
            node->right = newRight;
            newLeft->left = oldLeft;
            newLeft->right = nullptr;
            newRight->left = nullptr;
            newRight->right = oldRight;
        }

        return root;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
