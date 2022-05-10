#include <iostream>
#include <string>


using namespace std;


int calValue(const string& str)
{
    int weight[4] = {10000000, 10000, 100, 1};
    int index = 0;
    int result = 0;
    for (int i = 0; i < str.size();) {
        
        int j = i;
        while (j < str.size() && str[j] != '.') {
            j++;
        }

        string sub = str.substr(i, j - i);
        int val = atoi(sub.c_str());

        result += val * weight[index];
        index++;

        i = j + 1;
    }

    return result;
}


bool check(const string& version1, const string& version2)
{
    return calValue(version1) < calValue(version2);
}
int main()
{
    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        string tmpStr1, tmpStr2;
        cin >> tmpStr1 >> tmpStr2;

        if (check(tmpStr1, tmpStr2) == true) {
            std::cout << "true\n";
        }
        else {
            std::cout << "false\n";
        }
    }

    return 0;
}
