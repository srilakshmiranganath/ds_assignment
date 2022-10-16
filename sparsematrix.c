#include<stdio.h>

int main(){

    //Defining a structure
    typedef struct{
        int row;
        int col;
        int value;
    } elements;
    elements sparse[100];

    int rownum,colnum,valcount=0;
    int mat[100][100];
    printf("Enter number of rows : ");
    scanf("%d",&rownum);
        printf("Enter number of columns : ");
    scanf("%d",&colnum);

    //Creating Sparse matrix
    printf("Enter elements of matrix : \n");
    for(int i=0;i<rownum;i++){
        for(int j=0;j<colnum;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    printf("\n");

    //Displaying the matrix
    printf("The matrix is : \n");
    for(int i=0;i<rownum;i++){
        for(int j=0;j<colnum;j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    //Adding elements to sparse representation
      for(int i=0,z=1;i<rownum;i++){
        for(int j=0;j<colnum;j++){
            if(mat[i][j]!=0){
                valcount++;
                sparse[z].row=i;
                sparse[z].col=j;
                sparse[z].value=mat[i][j];
                z++;
            }            
        }
    }
    printf("\n");

    sparse[0].value=valcount;
    sparse[0].row=rownum;
    sparse[0].col=colnum;

    //Displaying the sparse representation
    printf("Sparse representation : \n");
    for(int i=0;i<=valcount;i++){
        printf("%d\t%d\t%d\n", sparse[i].row,sparse[i].col,sparse[i].value);
    }
    printf("\n");

    //Sparsity
    float sparsity=(float)(sparse[0].row*sparse[0].col-sparse[0].value)/(sparse[0].row*sparse[0].col);
    printf("Sparsity : %0.2f\n", sparsity);
    
}