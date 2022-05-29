#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    struct Pillar_t {
        int index;
        int height;
        Pillar_t(int i, int h) {
            this->index = i;
            this->height = h;
        }
    };

public:
    int trap(vector<int>& height) {

        int result = 0;
        stack<Pillar_t> stk;
        for (int i = 0; i < height.size(); i++) {

            int h = height[i];
            while (stk.empty() == false && stk.top().height < h) {

                Pillar_t right = stk.top();
                stk.pop();

                if (stk.empty() == false) {

                    Pillar_t left = stk.top();

                    int S = (min(h, left.height) - right.height) * (i - left.index - 1);
                    result += S;
                }
            }

            stk.push(Pillar_t(i, h));
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    cout << sol.trap(height) << endl;


    return 0;
}
