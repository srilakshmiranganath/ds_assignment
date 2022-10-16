#include<stdio.h>
int main(){
    typedef struct{
        int row;
        int col;
        int value;
    } elements;
    elements sparse[100];
    int rownum,colnum,valcount;

    //Obtaining elements of sparse representation
    printf("Enter number of rows, columns, and non-zero values in the matrix : ");
    scanf("%d%d%d",&rownum,&colnum,&valcount);
    printf("Enter the row, column, and value in sparse representation : \n");
    for(int i=1;i<=valcount;i++){
        scanf("%d%d%d",&sparse[i].row,&sparse[i].col,&sparse[i].value);
    }

    sparse[0].row=rownum;
    sparse[0].col=colnum;
    sparse[0].value=valcount;

    printf("Sparse representation of the matrix : \n");
    for(int i=0;i<=valcount;i++){
        printf("%d\t%d\t%d\n",sparse[i].row,sparse[i].col,sparse[i].value);
    }
    printf("\n");

    //Obtaining transpose using fast transpose method
    for (int i = 1; i <= valcount; i++)
    {
        int temp = sparse[i].row;
        sparse[i].row = sparse[i].col;
        sparse[i].col = temp;
    }

    //Printing transpose
    printf("Transpose : \n");
    for(int i=0;i<=valcount;i++){
        printf("%d\t%d\t%d\n",sparse[i].row,sparse[i].col,sparse[i].value);
    }
}