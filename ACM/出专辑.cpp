#include <iostream>

using namespace std;

int main()
{
    int n, s, L;
    cin >> n >> s >> L;

    int ans = 0;
    while (n > 0) {
        int sum = 0;
        int step = 0;
        while (1) {
            sum = step * (s + 1) + s;
            if (sum > L) {
                break;
            }
            else if (sum == L) {
                step++;
                break;
            }
            
            step++;
        }

        n -= step;
        ans++;
    }

    std::cout << ans << endl;
}
