#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>

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
    unordered_map<int, int> sumTimes;

    //获取子树结点的和
    int getSubTreeSum(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }
        
        int leftSum = getSubTreeSum(root->left);
        int rightSum = getSubTreeSum(root->right);

        int sum = root->val + leftSum + rightSum;
        sumTimes[sum]++;

        return sum;
    }

    struct Node
    {
        int sum;
        int times;
    };
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {

        vector<int> result;
        getSubTreeSum(root);

        vector<Node> vecTmp;

        for (auto& it : sumTimes) {
            vecTmp.push_back({ it.first, it.second });
        }

        sort(vecTmp.begin(), vecTmp.end(), [](const Node& a, const Node& b) {
            return a.times > b.times;
        });

        result.push_back(vecTmp[0].sum);
        for (int i = 1; i < vecTmp.size(); i++) {
            if (vecTmp[i].times == vecTmp[i - 1].times) {
                result.push_back(vecTmp[i].sum);
            }
            else {
                break;
            }
        }

        return result;
    }
};

/*
4 1
2 1
-3 1

*/

int main()
{
    std::cout << "Hello World!\n";
}
