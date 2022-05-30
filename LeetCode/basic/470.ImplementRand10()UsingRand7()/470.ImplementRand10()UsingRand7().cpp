#include <iostream>

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

int rand7()
{

}
class Solution {
public:
    int rand10() {
        int i = rand7() - 1;
        int j = rand7() - 1;

        //val的范围是0到49
        int val = i * 7 + j;
        
        if (val >= 40) {
            return rand10();
        }
        else {
            return val % 10 + 1;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
