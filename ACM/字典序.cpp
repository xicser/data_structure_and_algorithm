#include <queue>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct cmp
{
    bool operator()(long long a, long long b) {
        string s1 = to_string(a);
        string s2 = to_string(b);

        return s1 < s2;
    }
};

int main()
{
    long long n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, cmp> que;

    //que.push("1");
    //que.push("10");
    //que.push("100");
    //que.push("101");
    //que.push("2");

    for (int i = 1; i <= n; i++) {
        if (que.size() < m) {
            que.push(i);
        }
        else {
            que.push(i);
            que.pop();
        }
    }

    //while (que.empty() == false)
    //{
    //    cout << que.top() << endl;
    //    que.pop();
    //}

    std::cout << que.top() << endl;

    return 0;
}
