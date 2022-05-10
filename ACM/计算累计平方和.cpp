// 计算累计平方和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

long long cal(long long val)
{
    vector<int> bits;
    int temp = val;

    while (temp > 0) {
        bits.push_back(temp % 10);
        temp /= 10;
    }

    long long result = 0;

    for (int i : bits) {
        result += i * i;
    }

    return result;
}

int main()
{
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;

        bool hasResult = false;
        int cnt = 100;
        while (cnt) {
            val = cal(val);
            if (val == 1) {
                hasResult = true;
                break;
            }
            else {
                cnt--;
            }
        }
        if (hasResult == true) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }

    return 0;
}
