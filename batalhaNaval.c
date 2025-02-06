#include <stdio.h>

int main()
{
    int matrix[10][10] = {};
    int startLine, startCol; // for diagonal ships

    // fill matrix
    for (int l = 0; l < 10; l++)
    {
        for (int c = 0; c < 10; c++)
        {
            matrix[l][c] = 0;
        }
    }

    // create vertical and horizontal ships
    for (int l = 0; l < 10; l++)
    {
        for (int c = 0; c < 10; c++)
        {
            // vertical
            if (c == 2 && l > 2 && l < 7)
            {
                matrix[l][c] = 3;
            }

            // horizontal
            if (l == 8 && c > 3 && c < 8)
            {
                matrix[l][c] = 3;
            }
        }
    }

    // create diagonal up right ship
    startLine = 5;
    startCol = 5;

    for (int i = 0; i < 4; i++)
    {
        matrix[startLine - i][startCol + i] = 3;
    }

    // create diagonal down left ship
    startLine = 0;
    startCol = 1;

    for (int i = 0; i < 4; i++)
    {
        matrix[startLine + i][startCol + i] = 3;
    }

    // show matrix
    for (int l = 0; l < 10; l++)
    {
        for (int c = 0; c < 10; c++)
        {
            printf("%d ", matrix[l][c]);
        }
        printf("\n");
    }

    return 0;
}
