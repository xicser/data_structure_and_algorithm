#include <iostream>
#include <vector>
#include <unordered_map>
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
public:
    vector<int> findMode(TreeNode* root) {
        process(root);

        vector< pair<int, int> > resultTmp(numsCount.begin(), numsCount.end());
        sort(resultTmp.begin(), resultTmp.end(), [](const pair<int, int>& v1, const pair<int, int>& v2){
            return v1.second > v2.second;
        });

        if (numsCount.size() == 1) {
            return {resultTmp[0].first};
        }

        vector<int> result;
        unsigned int i;
        for (i = 0; i < resultTmp.size() - 1; i++) {

            result.push_back(resultTmp[i].first);
            if (resultTmp[i].second != resultTmp[i + 1].second) {
                break;
            }
        }
        if (i == resultTmp.size() - 1) {
            if (resultTmp[i].second == resultTmp[i - 1].second) {
                result.push_back(resultTmp[i].first);
            }
        }

        return result;
    }

private:
    void process(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        process(root->left);
        numsCount[root->val]++;
        process(root->right);
    }

    unordered_map<int, int> numsCount;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
