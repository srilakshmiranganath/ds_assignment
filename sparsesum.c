#include<stdio.h>
int main(){
    typedef struct{
        int row;
        int col;
        int value;
    } elements;
    elements fsparse[100],ssparse[100],sumsparse[100];
    int fvalcount,svalcount,frownum,fcolnum,srownum,scolnum;

    //Obtaining sparse representation of first matrix
    printf("Enter number of rows, columns, and non-zero values in first matrix : ");
    scanf("%d%d%d",&frownum,&fcolnum,&fvalcount);
    printf("Enter the row, column, and value in sparse representation : \n");
    for(int i=1;i<=fvalcount;i++){
        scanf("%d%d%d",&fsparse[i].row,&fsparse[i].col,&fsparse[i].value);
    }

    fsparse[0].row=frownum;
    fsparse[0].col=fcolnum;
    fsparse[0].value=fvalcount;

    printf("Sparse representation of first matrix : \n");
    for(int i=0;i<=fvalcount;i++){
        printf("%d\t%d\t%d\n",fsparse[i].row,fsparse[i].col,fsparse[i].value);
    }

    //Obtaining sparse representation of second matrix
    printf("Enter number of rows, columns, and non-zero values in second matrix : ");
    scanf("%d%d%d",&srownum,&scolnum,&svalcount);
    printf("Enter the row, column, and value in sparse representation : \n");
    for(int i=1;i<=svalcount;i++){
        scanf("%d%d%d",&ssparse[i].row,&ssparse[i].col,&ssparse[i].value);
    }

    ssparse[0].row=srownum;
    ssparse[0].col=scolnum;
    ssparse[0].value=svalcount;

    printf("Sparse representation of second matrix : \n");
    for(int i=0;i<=svalcount;i++){
        printf("%d\t%d\t%d\n",ssparse[i].row,ssparse[i].col,ssparse[i].value);
    }

    //Sparse representation of sum
    if(fsparse[0].row!=ssparse[0].row || fsparse[0].col!=ssparse[0].col){
        printf("Addition not possible\n");
    }
    sumsparse[0].row=fsparse[0].row;
    sumsparse[0].col=fsparse[0].col;

    int a=1,b=1,c=1;
    for(int i=0;i<ssparse[0].row;i++){
        for(int j=0;j<ssparse[0].col;j++){
            if(fsparse[a].row==i && fsparse[a].col==j && ssparse[b].row==j && ssparse[b].col==j){
                sumsparse[c].row=i;
                sumsparse[c].col=j;
                sumsparse[c].value=fsparse[a].value+ssparse[b].value;
                a++;
                b++;
                c++;
            }

            else if(fsparse[a].row==i && fsparse[a].col==j){
                sumsparse[c].row=i;
                sumsparse[c].col=j;
                sumsparse[c].value=ssparse[a].value;
                a++;
                c++;
            }

            else if(ssparse[b].row==i && ssparse[b].col==j){
                sumsparse[c].row=i;
                sumsparse[c].col=j;
                sumsparse[c].value=ssparse[b].value;
                b++;
                c++;
            }
        }
    }
    sumsparse[0].value=--c;

    printf("Sparse representation of sum : \n");
    for(int i=0;i<=sumsparse[0].value;i++){
        printf("%d\t%d\t%d\n",sumsparse[i].row,sumsparse[i].col,sumsparse[i].value);
    }

    return 0;
}