#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* sortedListToBST(ListNode* head) {

        vector<int> nums;
        getNums(head, nums);
        return process(nums, 0, nums.size() - 1);
    }

    TreeNode* process(vector<int> &nums, int start, int end) {

        if (start > end) {
            return nullptr;
        }

        int mid = (start + end) / 2;
        TreeNode* nodeRoot = new TreeNode(nums[mid]);

        nodeRoot->left = process(nums, start, mid - 1);
        nodeRoot->right = process(nums, mid + 1, end);

        return nodeRoot;
    }

    void getNums(ListNode* head, vector<int> &nums) {
        while (head != nullptr) {
            nums.push_back(head->val);
            head = head->next;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
