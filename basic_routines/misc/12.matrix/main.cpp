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
int colIndex = 5;

/* zigzag¥Ú”°æÿ’Û */
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
void printArrayZigZag()
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

int main()
{
    printArrayZigZag();

    return 0;
}
