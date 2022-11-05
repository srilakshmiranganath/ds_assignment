#include<stdio.h>
void main() {
	int n, a[50],i,j,mode=0,temp,count=0,maxcount=0,sum=0;
	float mean,median;
	printf("Enter number of elements : ");
	scanf("%d",&n);
	printf("Enter elements : ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		sum=sum+a[i];
		}
	mean=sum/n;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	if(n%2==0)
		median=(a[n/2]+a[(n/2)+1])/2;
	else
		median=a[n/2];
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]==a[j])
			count++;
			if(count>maxcount){
				maxcount=count;
				mode=a[i];
				}
			}
		}
	printf("Mean is : %f\n" ,mean);
	printf("Median is : %f\n" ,median);
	printf("Mode is : %d\n",mode);
}
