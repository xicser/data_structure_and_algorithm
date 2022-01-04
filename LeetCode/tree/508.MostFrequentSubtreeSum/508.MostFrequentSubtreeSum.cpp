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
    unordered_map <int, int> sumTimes;

    //获取子树结点的和
    int getSubTreeSum(TreeNode* root) {

        if (root == nullptr) {
            return 0;
        }

        //获取左子树
        int leftSum = getSubTreeSum(root->left);

        //获取右子树
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

        for (auto it : sumTimes) {
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
