#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string num1;
    string num2;
    cin >> num1 >> num2;

    num1.erase(num1.begin());
    num1.erase(--num1.end());
    num2.erase(num2.begin());
    num2.erase(--num2.end());


    long long a = atol(num1.c_str());
    long long b = atol(num2.c_str());

    cout << "\"" << a + b << "\"" << endl;

    return 0;
}

//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//void copePlus(string& num1, string& num2)
//{
//    string result;
//
//    int i = num1.size() - 1, j = num2.size() - 1;
//    int carry = 0;
//    while (i >= 0 && j >= 0) {
//
//        int sum = (num1[i] - 48) + (num2[j] - 48) + carry;
//        int ge = sum % 10;
//        carry = sum / 10;
//
//        result.push_back(ge + 48);
//
//        i--;
//        j--;
//    }
//
//    while (i >= 0) {
//        int sum = (num1[i] - 48) + carry;
//        int ge = sum % 10;
//        carry = sum / 10;
//
//        result.push_back(ge + 48);
//
//        i--;
//    }
//
//    while (j >= 0) {
//        int sum = (num2[j] - 48) + carry;
//        int ge = sum % 10;
//        carry = sum / 10;
//
//        result.push_back(ge + 48);
//
//        j--;
//    }
//
//    if (carry != 0) {
//        result.push_back(carry + 48);
//    }
//
//    reverse(result.begin(), result.end());
//
//    cout << result;
//}
//
///*
//  9999
//- 8811
//num1 - num2
//调用前要保证num1始终大于num2
//*/
//void copeMinus(string& num1, string& num2)
//{
//    string result;
//
//    int i = num1.size() - 1, j = num2.size() - 1;
//    while (i >= 0 && j >= 0) {
//        int val1 = num1[i] - 48;
//        int val2 = num2[j] - 48;
//
//        if (val1 >= val2) {
//            result.push_back(val1 - val2 + 48);
//        }
//        else {
//            val1 += 10;     //借位
//            num1[i - 1]--;
//
//            result.push_back(val1 - val2 + 48);
//        }
//
//        i--;
//        j--;
//    }
//
//    while (i >= 0) {
//
//        int val1 = num1[i] - 48;
//        int val2 = 0;
//
//        if (val1 >= val2) {
//            if (i != 0) {
//                result.push_back(val1 - val2 + 48);
//            }
//            else {
//                if (val1 - val2 != 0) {
//                    result.push_back(val1 - val2 + 48);
//                }
//            }
//        }
//        else {
//            val1 += 10;     //借位
//            num1[i - 1]--;
//
//            result.push_back(val1 - val2 + 48);
//        }
//        i--;
//    }
//
//    reverse(result.begin(), result.end());
//
//    cout << result;
//}
//
///* 判断num1和num2谁大
//num1 > num2 : return 1
//num1 < num2 : return -1
//num1 == num2 : return 0
//*/
//int checkBig(const string& num1, const string& num2)
//{
//    if (num1.size() > num2.size()) {
//        return 1;
//    }
//
//    if (num1.size() < num2.size()) {
//        return -1;
//    }
//
//    int i = 0, j = 0;
//
//    while (i < num1.size()) {
//
//        if (num1[i] > num2[j]) {
//            return 1;
//        }
//        else if (num1[i] < num2[j]) {
//            return -1;
//        }
//
//        i++;
//        j++;
//    }
//
//    return 0;
//}
//
//
//int main()
//{
//    string num1;
//    string num2;
//    cin >> num1 >> num2;
//
//    num1.erase(num1.begin());
//    num1.erase(--num1.end());
//    num2.erase(num2.begin());
//    num2.erase(--num2.end());
//
//
//    if (num1[0] != '-' && num2[0] != '-') {
//        cout << "\"";
//        copePlus(num1, num2);
//        cout << "\"";
//    }
//    else if (num1[0] == '-' && num2[0] == '-') {
//        num1.erase(num1.begin());
//        num2.erase(num2.begin());
//        cout << "\"";
//        cout << "-";
//        copePlus(num1, num2);
//        cout << "\"";
//    }
//    else if (num1[0] == '-' && num2[0] != '-') {
//        num1.erase(num1.begin());
//
//        int bigLittle = checkBig(num1, num2);
//        if (bigLittle == 0) {
//            cout << "\"0\"" << endl;
//            return 0;
//        }
//        else if (bigLittle == 1) {
//            cout << "\"";
//            cout << '-';
//            copeMinus(num1, num2);
//            cout << "\"";
//        }
//        else {
//            cout << "\"";
//            copeMinus(num2, num1);
//            cout << "\"";
//        }
//    }
//    else {
//        string temp = num1;
//        num1 = num2;
//        num2 = temp;
//
//        num1.erase(num1.begin());
//
//        int bigLittle = checkBig(num1, num2);
//        if (bigLittle == 0) {
//            cout << "\"0\"" << endl;
//            return 0;
//        }
//        else if (bigLittle == 1) {
//            cout << "\"";
//            cout << '-';
//            copeMinus(num1, num2);
//            cout << "\"";
//        }
//        else {
//            cout << "\"";
//            copeMinus(num2, num1);
//            cout << "\"";
//        }
//    }
//
//    return 0;
//}
