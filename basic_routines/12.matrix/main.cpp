#include <iostream>

using namespace std;



int matrix[4][6] =
{
    {1, 2,   3,  4,  3,  4},
    {5, 6,   7,  8,  3,  4},
    {9, 10, 11, 12,  3,  4},
    {9, 10, 11, 12,  3,  4}
};

int rowIndex = 3;
int colIndex = 3;

/* zigzag打印矩阵 */
static void printLevel(int aPosR, int aPosC, int bPosR, int bPosC, bool dir)
{
    if (dir == true) {

        while (aPosR != bPosR && aPosC != bPosC) {
            printf("%d ", matrix[aPosR][aPosC]);
            aPosR++;
            aPosC--;
        }
        printf("%d ", matrix[aPosR][aPosC]);
    }
    else {

        while (aPosR != bPosR && aPosC != bPosC) {
            printf("%d ", matrix[bPosR][bPosC]);
            bPosR--;
            bPosC++;
        }
        printf("%d ", matrix[bPosR][bPosC]);
    }
}
void printMatrixZigZag()
{
    int Ar = 0, Ac = 0;
    int Br = 0, Bc = 0;
    bool dir = false;

    while (Ar != rowIndex + 1) {
//        printf("A(%d, %d)    B(%d, %d)\n", Ar, Ac, Br, Bc);
        printLevel(Ar, Ac, Br, Bc, dir);

        Ar = Ac != colIndex ? Ar : Ar + 1;
        Ac = Ac != colIndex ? Ac + 1 : Ac;

        Bc = Br != rowIndex ? Bc : Bc + 1;
        Br = Br != rowIndex ? Br + 1 : Br;

        dir = !dir;
    }
}

/* 圆圈打印矩阵 */
static void printEdge(int top, int left, int bottom, int right)
{
//    printf("A(%d %d)    B(%d %d)\n", top, left, bottom, right);
    int x, y;

    if (top == bottom) {
        x = left;
        while (x <= right) {
            printf("%d ", matrix[top][x]);
            x++;
        }
        return;
    }
    else if (left == right) {
        y = top;
        while (y <= bottom) {
            printf("%d ", matrix[y][left]);
            y++;
        }
        return;
    }

    x = left;
    y = top;
    while (x < right) {
        printf("%d ", matrix[y][x]);
        x++;
    }

    x = right;
    y = top;
    while (y < bottom) {
        printf("%d ", matrix[y][x]);
        y++;
    }

    x = right;
    y = bottom;
    while (x > left) {
        printf("%d ", matrix[y][x]);
        x--;
    }

    x = left;
    y = bottom;
    while (y > top) {
        printf("%d ", matrix[y][x]);
        y--;
    }
}
void printMatrixCircle()
{
    int top = 0, left = 0;
    int bottom = rowIndex, right = colIndex;

    while (top <= bottom && left <= right) {
        printEdge(top, left, bottom, right);

        top++;
        left++;
        bottom--;
        right--;
    }
}

/* 矩阵逆时针旋转90° */
static void matrixRotation(int top, int left, int bottom, int right)
{
    int cnt = right - left;
    for (int i = 0; i < cnt; i++) {
        int swapTmp;
        swapTmp = matrix[top][left + i];

        matrix[top][left + i] = matrix[top + i][right];
        matrix[top + i][right] = matrix[bottom][right - i];
        matrix[bottom][right - i] = matrix[bottom - i][left];
        matrix[bottom - i][left] = swapTmp;
    }
}
void printMatrixRotation()
{
    int top = 0, left = 0;
    int bottom = rowIndex, right = colIndex;

    while (top <= bottom && left <= right) {
        matrixRotation(top, left, bottom, right);

        top++;
        left++;
        bottom--;
        right--;
    }
}

void printMatrix()
{
    for (int i = 0; i <= rowIndex; i++) {
        for (int j = 0; j <= colIndex; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main()
{
//    printMatrixZigZag();
//    printf("\n");

//    printMatrixCircle();
//    printf("\n");

    printMatrix();
    printf("\n");
    printMatrixRotation();
    printMatrix();
    printf("\n");

    return 0;
}
