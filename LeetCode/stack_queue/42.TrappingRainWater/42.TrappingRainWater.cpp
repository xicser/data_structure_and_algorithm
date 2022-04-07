#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
private:
    //柱子
    typedef struct Pillar_t {
        int index;
        int height;
        Pillar_t() {
        }
        Pillar_t(int _index, int _height) {
            index = _index;
            height = _height;
        }
    } Pillar_t;

    stack<Pillar_t> stk;

public:
    int trap(vector<int>& height) {

        int result = 0;
        for (int i = 0; i < height.size(); i++) {

            int h = height[i];

            //保持栈的单调性
            while (stk.empty() == false && stk.top().height < h) {

                Pillar_t pillarRight = stk.top();
                stk.pop();

                if (stk.empty() == false) {

                    Pillar_t pillarLeft = stk.top();

                    int S = (min(pillarLeft.height, h) - pillarRight.height) *      //高
                                        (i - pillarLeft.index - 1);                 //底
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
