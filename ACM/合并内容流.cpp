#include <iostream>
#include <vector>

using namespace std;


char A[1000];
char B[1000];
int main()
{
    cin.getline(A, 1000, '\n');
    cin.getline(B, 1000, '\n');

    string strA(A), strB(B);

    vector<string> vect1;
    for (int i = 0; i < strA.size(); ) {

        int j = i;
        while (j < strA.size() && strA[j] != ' ') {
            j++;
        }

        string sub = strA.substr(i, j - i);
        vect1.push_back(sub);

        i = j + 1;
    }

    vector<string> vect2;
    for (int i = 0; i < strB.size(); ) {

        int j = i;
        while (j < strB.size() && strB[j] != ' ') {
            j++;
        }

        string sub = strB.substr(i, j - i);
        vect2.push_back(sub);

        i = j + 1;
    }

    vector<string> result;
    int index1 = 0;
    int index2 = 0;

    if (vect1.size() < 4) {
        goto label;
    }

    while (index1 < vect1.size() && index2 < vect2.size()) {

        for (int i = index1; i < index1 + 4; i++) {
            result.push_back(vect1[i]);
        }
        index1 += 4;

        result.push_back(vect2[index2]);
        index2++;

        //vect1剩下的少于4个
        if (vect1.size() - index1 < 4) {
            break;
        }
    }

label:
    for (int i = index1; i < vect1.size(); i++) {
        result.push_back(vect1[i]);
    }
    for (int i = index2; i < vect2.size(); i++) {
        result.push_back(vect2[i]);
    }


    for (int i = 0; i < result.size(); i++) {
        if (i == result.size() - 1) {
            cout << result[i] << endl;
        }
        else {
            cout << result[i] << " ";
        }
    }

    return 0;
}
