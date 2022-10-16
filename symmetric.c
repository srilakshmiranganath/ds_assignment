#include <stdio.h>

typedef struct
{
    int row;
    int col;
    int value;
} elements;

int main()
{
    int valcount;
    printf("Enter number of non-zero elements : ");
    scanf("%d", &valcount);

    elements mat[valcount + 1];
    mat[0].value = valcount;

    //Obtaining sparse representation
    printf("Enter number of rows and coloumns: ");
    scanf("%d %d", &mat[0].row, &mat[0].col);
    printf("\n");

    printf("Enter row, column, and value : \n");
    for (int i = 1; i <= valcount; i++)
        scanf("%d%d%d", &mat[i].row, &mat[i].col, &mat[i].value);

    printf("Sparse matrix representation : \n");
    for (int i = 0; i <= valcount; i++)
        printf("%d\t%d\t%d\n", mat[i].row, mat[i].col, mat[i].value);
    printf("\n");

    //Checking for symmetric matrix
    if (mat[0].row != mat[0].col)
    {
        printf("Not square matrix\n");
        return 1;
    }
    int flag = 0;
    for (int i = 1; i <= valcount; i++)
    {
        flag = 0;
        for (int j = 1; j <= valcount; j++)
            if (mat[i].row == mat[j].col && mat[i].col == mat[j].row && mat[i].value == mat[j].value)
                flag = 1;
        if (flag == 0)
        {
            printf("Not a symmetric matrix\n");
            return 1;
        }
    }
    printf("Symmetric sparse matrix\n");

    return 0;
}