#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int N, M;

    cin >> N >> M;

    vector<int> input(N, 0);

    for (int i = 0; i < M; i++) {
        int L, R;

        cin >> L >> R;

        fill(input.begin() + L, input.begin() + R + 1, i + 1);
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        sum += i * input[i] % 100000009;
    }

    std::cout << sum % 100000009 << endl;

    return 0;
}
