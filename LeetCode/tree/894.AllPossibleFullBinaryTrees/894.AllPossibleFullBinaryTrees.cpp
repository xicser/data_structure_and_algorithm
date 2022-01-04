#include <iostream>
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
    //递归含义：使用n个节点，构造所有可能的满二叉树, 返回所有树的根节点
    vector<TreeNode*> allPossibleFBT(int n) {

        if (n % 2 == 0) {
            return {};
        }

        //如果只有一个节点, 那么直接new出来就行了
        if (n == 1) {
            return { new TreeNode(0, nullptr, nullptr) };
        }

        vector<TreeNode*> result;

        int leftCnt = 1;
        while (leftCnt <= n - 2)   //以此遍历节点个数, 从小到大
        {
            int rightCnt = n - leftCnt - 1;
            vector<TreeNode*> leftTrees = allPossibleFBT(leftCnt);      //构建左子树的列表
            vector<TreeNode*> rightTrees = allPossibleFBT(rightCnt);    //构建右子树的列表

            for (int i = 0; i < leftTrees.size(); i++) {
                for (int j = 0; j < rightTrees.size(); j++) {
                    TreeNode* rootNode = new TreeNode(0);
                    rootNode->left = leftTrees[i];
                    rootNode->right = rightTrees[j];

                    result.push_back(rootNode);
                }
            }

            //+2, 因为奇数节点不可能创建满二叉树
            leftCnt += 2;
        }

        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
