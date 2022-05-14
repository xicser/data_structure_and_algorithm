#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
vector<int> transResult;


void trans(const vector<int>& tree, int node)
{
    if (node >= tree.size()) {
        return;
    }

    trans(tree, node * 2 + 1);

    transResult.push_back(tree[node]);

    trans(tree, node * 2 + 2);
}

int main()
{
    string input;
    cin >> input;
    if (input == "None") {
        cout << "True" << endl;
        return 0;
    }

    for (int i = 0; i < input.size(); ) {

        int j = i;
        while (j < input.size() && input[j] != ',') {
            j++;
        }

        string sub = input.substr(i, j - i);
        tree.push_back(atoi(sub.c_str()));

        i = j + 1;
    }

    trans(tree, 0);

    for (int i = 1; i < transResult.size(); i++) {
        if (transResult[i] < transResult[i - 1]) {
            cout << "False" << endl;
            return 0;
        }
    }
    cout << "True" << endl;

    return 0;
}
