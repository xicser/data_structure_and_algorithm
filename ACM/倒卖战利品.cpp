#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
5
1 1
1 2
1 3
3 2
4 4
*/
int main()
{
    int n;
    cin >> n;
    vector< vector<int> > inputs(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++) {
        cin >> inputs[i][0] >> inputs[i][1];
    }

    sort(inputs.begin(), inputs.end(), [](const vector<int>& v1, const vector<int>& v2) {
        if (v1[0] != v2[0]) {
            return v1[0] < v2[0];
        }
        else {
            return v1[1] < v2[1];
        }
    });

    int result = 1;

    vector<int> dp(inputs.size(), 1);

    for (int i = 1; i < inputs.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (inputs[i][0] >= inputs[j][0] && inputs[i][1] >= inputs[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        result = max(result, dp[i]);
    }



    cout << result << endl;

    return 0;
}
