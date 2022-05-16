#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

unordered_set<string> st;

//计算next数组
void makeNext(const string& pattern, vector<int>& next) {
    int len = 0;  //len表示index之前的最长相等前后缀的长度
    next[0] = 0;
    for (int index = 1; index < pattern.size(); index++) {

        while (len > 0 && pattern[len] != pattern[index]) {
            len = next[len - 1];
        }
        if (pattern[len] == pattern[index]) {
            len++;
        }

        next[index] = len;
    }
}

struct Interval
{
    int left, right;
    Interval(int _left, int _right) {
        left = _left;
        right = _right;
    }
};
vector<Interval> result;
void kmp(const string& text, const string& pattern)
{
    if (pattern.size() > text.size()) {
        return;
    }

    vector<int> next(pattern.size(), 0);
    makeNext(pattern, next);

    int index = -1;

    int i = 0, j = 0;  //i指向text, j指向pattern
    while (i < text.size()) {

        if (j == pattern.size() - 1 && pattern[j] == text[i]) {
            index = i - j;
            
            result.push_back(Interval(index, index + pattern.size() - 1));

            j = 0;
            i++;

            continue;
        }

        if (text[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            //得先找到第一个位置
            if (j == 0) {
                i++;
            }
            else {
                j = next[j - 1];
            }
        }
    }
}

int eraseOverlapIntervals(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [=](const Interval& I1, const Interval& I2) {
        //先按照左端点从大到小
        if (I1.left > I2.left) {
            return true;
        }
        //若左端点相同, 则按照右端点从小到大
        else if (I1.left == I2.left && I1.right < I2.right) {
            return true;
        }
        return false;
    });

    int result = 1; //至少需要一支箭
    int lastLeft = intervals[0].left;
    for (unsigned int i = 1; i < intervals.size(); i++) {
        int right = intervals[i].right;
        if (right < lastLeft) {
            result++;
            lastLeft = intervals[i].left;
        }
    }

    return result;
}
int main()
{
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string tempStr;
        cin >> tempStr;
        st.insert(tempStr);
    }

    string str;
    cin >> str;

    //先看看每个子串在str的区间范围
    for (auto& stri : st) {
        kmp(str, stri);
    }

    //选区间问题
    cout << eraseOverlapIntervals(result) << endl;

    return 0;
}
