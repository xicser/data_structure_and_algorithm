#include <iostream>
#include <stdio.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t result = 0;
        int bits = 31;
        for (int i = 0; i < 32; i++) {
            if (n & 1) {
                result |= (1 << bits);
            }
            n >>= 1;
            bits--;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    printf("%u\n", sol.reverseBits(4294967293));

    return 0;
}
