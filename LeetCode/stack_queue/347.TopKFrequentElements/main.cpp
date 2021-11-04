#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

#include <stdio.h>

using namespace std;

struct Node {
    int num;
    int cnt;
    Node(int _num, int _cnt) {
        num = _num;
        cnt = _cnt;
    }
	friend bool operator<(Node a, Node b)
	{
		return a.cnt < b.cnt;
	}
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> result;
        unordered_map<int, int> mapNumsCnt;
        for (unsigned int i = 0; i < nums.size(); i++) {
            mapNumsCnt[ nums[i] ]++;
        }

        priority_queue<Node> priQue;

        for (auto it = mapNumsCnt.begin(); it != mapNumsCnt.end(); it++) {
//            printf("%d %d\n", it->first, it->second);
            Node node(it->first, it->second);
            priQue.push(node);
        }

        for (int i = 0; i < k; i++) {
            result.push_back(priQue.top().num);
            priQue.pop();
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1};
    vector<int> result = sol.topKFrequent(nums, 1);

    for (unsigned int i = 0; i < result.size(); i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
