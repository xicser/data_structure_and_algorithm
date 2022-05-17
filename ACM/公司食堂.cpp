#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

void cope()
{
    int N;
    cin >> N;   //桌子数
    string nowSeat;
    cin >> nowSeat;
    int len = nowSeat.size();
    priority_queue<int, vector<int>, greater<int>> que0, que1, que2;        //que2表示有2个空位的位置
    for (int i = 0; i < len; i++) {
        switch (nowSeat[i])
        {
        case '2': que0.push(i); break;
        case '1': que1.push(i); break;
        case '0': que2.push(i); break;
        default: break;
        }
    }

    int M;
    cin >> M;   //即将就餐的人
    string sexes;
    cin >> sexes;

    vector<int> result(M);
    int index = 0;

    for (int i = 0; i < M; i++) {
        //男
        if (sexes[i] == 'M') {

            //男的先找1个空位的
            if (que1.size() != 0) {
                int _1_pos = que1.top();
                que1.pop();

                que0.push(_1_pos);

                result[index++] = _1_pos + 1;
            }
            //直接找2个空位的
            else {
                int _2_pos = que2.top();
                que2.pop();
                que1.push(_2_pos);

                result[index++] = _2_pos + 1;
            }
        }
        //女
        else {
            //女的先找2个空位的
            if (que2.size() != 0) {
                int _2_pos = que2.top();
                que2.pop();

                que1.push(_2_pos);

                result[index++] = _2_pos + 1;
            }
            //直接找1个空位的
            else {
                int _1_pos = que1.top();
                que1.pop();
                que0.push(_1_pos);

                result[index++] = _1_pos + 1;
            }
        }
    }

    for (int i = 0; i < index; i++) {
        printf("%d\n", result[i]);
    }
}
int main()
{
    int T;
    cin >> T;

    while (T--) {
        cope();
    }
    
    return 0;
}
