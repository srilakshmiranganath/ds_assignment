#include<stdio.h>
void main() {
	int s1[50],s2[50],s3[50],n1,n2,i,j,k;
	printf("Enter number of elements in set s1 : ");
	scanf("%d",&n1);
	printf("Enter the elements of s1 : ");
	for(i=0;i<n1;i++)
		scanf("%d",&s1[i]);
	printf("Enter number of elements in set s2 : ");
	scanf("%d",&n2);
	printf("Enter the elements of s2 : ");
	for(i=0;i<n2;i++)
		scanf("%d",&s2[i]);
	for(i=0;i<n1;i++)
		for(j=0;j<n2;j++)
			if(s1[i]==s2[j]){
				s3[k]=s1[i];
				k++;
			}
	printf("Intersection : ");
	for(i=0;i<k;i++)
		printf(" %d,",s3[i]);
}
