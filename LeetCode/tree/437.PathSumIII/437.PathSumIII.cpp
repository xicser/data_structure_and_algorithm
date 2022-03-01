#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<TreeNode*> nodes;
    void searchNodes(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        nodes.push_back(root);
        searchNodes(root->left);
        searchNodes(root->right);
    }

    int targetSum;
    int pathSumVal;
    int equalCnt;

    void find(TreeNode* root, int val) {
        if (root == nullptr) {
            return;
        }

        val += root->val;
        if (val == targetSum) {
            equalCnt++;
        }
        find(root->left, val);
        find(root->right, val);
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        this->searchNodes(root);  //先把所有节点都搜出来
        this->pathSumVal = 0;
        this->targetSum = targetSum;
        this->equalCnt = 0;

        for (int i = 0; i < nodes.size(); i++) {
            find(nodes[i], 0);
        }

        return this->equalCnt;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
