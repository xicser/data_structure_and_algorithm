#include <iostream>
#include <vector>

using namespace std;


int result = 0;
int k;
bool inArea(vector< vector<int> >& matrix, int x, int y)
{
    int row = matrix.size();
    int col = matrix[0].size();
    if (x < 0 || x >= row || y < 0 || y >= col) {
        return false;
    }

    return true;
}

bool isValid(int x, int y)
{
    int sum = 0;

    while (x) {
        sum += x % 10;
        x /= 10;
    }

    while (y) {
        sum += y % 10;
        y /= 10;
    }

    return sum <= k;
}

void dfs(vector< vector<int> >& matrix, int x, int y)
{
    if (inArea(matrix, x, y) == false) {
        return;
    }

    if (isValid(x, y) == false) {
        return;
    }

    //1被访问过
    if (matrix[x][y] == 1) {
        return;
    }

    //0没被访问过
    if (matrix[x][y] == 0) {
        result++;
        matrix[x][y] = 1;
    }

    dfs(matrix, x - 1, y);
    dfs(matrix, x + 1, y);
    dfs(matrix, x, y - 1);
    dfs(matrix, x, y + 1);
}


int main()
{
    int m, n;
    cin >> m >> n >> k;
    vector< vector<int> > matrix(m, vector<int>(n, 0));

    dfs(matrix, 0, 0);

    std::cout << result << endl;

    return 0;
}
