#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isBig(char c)
{
    if ('A' <= c && c <= 'Z') {
        return true;
    }
    return false;
}

bool isLittle(char c)
{
    if ('a' <= c && c <= 'z') {
        return true;
    }
    return false;
}

char upper(char c) {
    if (isBig(c) == true) {
        return c;
    }
    return (c - 32);
}

char down(char c) {
    if (isLittle(c) == true) {
        return c;
    }
    return (c + 32);
}

string merge(vector<string>& tokens) {
    string result;

    //大写
    for (int i = 0; i < tokens.size(); i++) {
        tokens[i][0] = upper(tokens[i][0]);
        result += tokens[i];
    }
    result += " ";

    //首字母小写
    tokens[0][0] = down(tokens[0][0]);
    for (int i = 0; i < tokens.size(); i++) {
        result += tokens[i];
    }
    result += " ";

    //dash
    for (int i = 0; i < tokens.size(); i++) {
        tokens[i][0] = down(tokens[i][0]);
        if (i != tokens.size() - 1) {
            result += tokens[i] + "_";
        }
        else {
            result += tokens[i];
        }
    }
    result += " ";

    //_
    for (int i = 0; i < tokens.size(); i++) {
        if (i != tokens.size() - 1) {
            result += tokens[i] + "-";
        }
        else {
            result += tokens[i];
        }
    }

    return result;
}

string copeBig(const string& str)
{    
    vector<string> tokens;
    for (int i = 0; i < str.size(); ) {

        if (isBig(str[i]) == true) {

            int j = i + 1;
            while (j < str.size() && isBig(str[j]) == false) {
                j++;
            }

            tokens.emplace_back(str.substr(i, j - i));

            i = j;
        }
        else {
            i++;
        }
    }

    return merge(tokens);
}

string cope_(const string& str, char dim)
{
    vector<string> tokens;
    for (int i = 0; i < str.size(); ) {

        int j = i;
        while (j < str.size() && str[j] != dim) {
            j++;
        }

        tokens.emplace_back(str.substr(i, j - i));

        i = j + 1;
    }

    return merge(tokens);
}


void process(string& str) {

    if (isBig(str[0]) == true) {
        cout << copeBig(str) << endl;
    }
    else {
        bool has_ = false;
        bool has_dash = false;

        for (char c : str) {
            if (c == '-') {
                has_dash = true;
                break;
            }
            if (c == '_') {
                has_ = true;
                break;
            }
        }
        if (has_ == true) {
            //
            cout << cope_(str, '_') << endl;
        }
        else if (has_dash == true) {
            //
            cout << cope_(str, '-') << endl;
        }
        else {
            str[0] = upper(str[0]);
            cout << copeBig(str) << endl;
        }
    }
}



int main()
{
    string str;
    cin >> str;
    process(str);

    return 0;
}
