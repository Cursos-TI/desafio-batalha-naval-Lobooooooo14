#include <stdio.h>

int main()
{
    int matrix[10][10] = {};
    int startLine, startCol; // aux

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

    // create diagonal right ship
    startLine = 5;
    startCol = 5;

    for (int i = 0; i < 4; i++)
    {
        matrix[startLine - i][startCol + i] = 3;
    }

    // create diagonal left ship
    startLine = 0;
    startCol = 1;

    for (int i = 0; i < 4; i++)
    {
        matrix[startLine + i][startCol + i] = 3;
    }

    // create skills - triangle
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= i * 2; j++)
        {
            matrix[8 + i][1 - i + j] = 1;
        }
    }

    // create skills - cross
    for (int l = 0; l < 10; l++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (l == 0 && c == 4)
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (i == 1 || j == 1)
                        {
                            matrix[l + i][c + j] = 1;
                        }
                    }
                }
            }
        }
    }

    // create skills - rhombus
    for (int l = 0; l < 10; l++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (l == 5 && c == 5)
            {
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (i == 1 || j == 1)
                        {
                            matrix[l + i][c + j] = 1;
                        }

                        if (i == 1 && j == 0)
                        {
                            matrix[l + 1][c - 1] = 1;
                            matrix[l + 1][c + 3] = 1;
                        }
                    }
                }
            }
        }
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
