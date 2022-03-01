#include <iostream>
#include <vector>
#include <set>
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
    priority_queue<int, vector<int>, greater<int> > queue;
    void traverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        traverse(root->left);
        queue.push(root->val);
        traverse(root->right);
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        traverse(root1);
        traverse(root2);

        vector<int> result;
        while (queue.empty() == false) {
            result.push_back(queue.top());
            queue.pop();
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

