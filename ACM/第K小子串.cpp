#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int k;
    cin >> k;

    set<string> s;
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            
            string sub = str.substr(i, j - i + 1);

            if (s.count(sub) != 0) {
                continue;
            }

            if (s.size() < k) {
                s.insert(sub);
            }
            else {

                //如果当前sub大于等于set的最后一个元素, 则没有必要insert
                string endStr = *(--s.end());
                if (sub >= endStr) {
                    continue;
                }

                s.insert(sub);
                s.erase(--s.end());
            }
        }
    }

    cout << *(--s.end()) << endl;

    return 0;
}


//cout << sub << endl;
