#include<stdio.h>
	typedef struct{
		int row;
		int col;
		int value;
	} elements;
	
void fasttranspose(elements a[], elements b[]){
	int row_terms[100], start_pos[100];
	int i,  j,  p;       

	int numTerms = a[0].value;
	int numCols = a[0].col;
             
	b[0].row = numCols;
	b[0].col = a[0].row;
	b[0].value = numTerms;
	if(numTerms>0){
	for(i =0; i<numCols;  i++)
		row_terms[i] = 0;

	for(i=1; i<=numTerms; i++)
		row_terms[a[i].col]++;

	start_pos[0]=1;

	for(i=1; i<numCols; i++)
		start_pos[i] = start_pos[i-1] + row_terms[i-1];

	for(i=1; i<=numTerms; i++){
		j = start_pos[a[i].col]++;
		b[j].row = a[i].col;
		b[j].col = a[i].row;
		b[j].value = a[i].value;
		}
	}
	printf("\nThe Fast Transpose sparse matrix is:\n");
	for(p=0; p<=a[0].value; p++){
		printf("%d\t", b[p].row);
		printf("%d\t", b[p].col);
		printf("%d\n", b[p].value);
		}
}

int main(){	
	elements a[100], b[100];
	int arownum,acolnum,avalcount;
	
	//Getting elements from user
	printf("Enter total number of rows, columns and non-zero values : ");
	scanf("%d%d%d",&arownum,&acolnum,&avalcount);
	
	printf("Enter row, column and non-zero value : \n");
	for(int i=1;i<=avalcount;i++){
		scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].value);
	}
	
	a[0].row=arownum;
	a[0].col=acolnum;
	a[0].value=avalcount;

	fasttranspose(a,b);
	
}
