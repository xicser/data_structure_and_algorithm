#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

//"[","]","(",")"
bool isCorrect(char *str)
{
    stack <char> st;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {

        if (str[i] == '[' || str[i] == '(') {
            st.push(str[i]);
        } else {
            if (st.empty()) return false;
            switch (str[i]) {
                case ']':
                    if (st.top() == '[') {
                        st.pop();
                    } else return false;
                    break;

                case ')':
                    if (st.top() == '(') {
                        st.pop();
                    } else return false;
                    break;

                default: break;
            }
        }
    }

    if (st.empty()) return true;
    else return false;
}

char str[10005];
int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        getchar();
        scanf("%s", str);
        if (isCorrect(str)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
