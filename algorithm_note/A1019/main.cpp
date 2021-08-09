/*

General Palindromic Number

*/

#include <iostream>

using namespace std;

//判断array是否为回文
bool isPalindrome(int *array,  int len)
{
    for (int i = 0; i < len / 2; i++) {
        if (array[i] != array[len - i - 1]) {
            return false;
        }
    }
    return true;
}


int main()
{
    int n, b;

    cin >> n >> b;

    int z[100], num = 0;
    do {
        z[num++] = n % b;
        n /= b;

    } while (n);

    if (isPalindrome(z, num)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    for (int i = num - 1; i >= 0; i--) {
        printf("%d", z[i]);
        if (i != 0) printf(" ");
        else printf("\n");
    }

    return 0;
}
