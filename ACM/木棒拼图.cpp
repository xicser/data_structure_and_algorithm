#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    multiset<int> st;

    for (int i = 0; i < n; i++) {
        int op, len;
        cin >> op >> len;

        if (op == 1) {
            sum += len;
            st.insert(len);
        }
        else {
            sum -= len;
            st.erase(st.find(len));
        }

        int max = *(--st.end());
        if (sum - max > max) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}
