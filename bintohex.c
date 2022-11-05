#include <stdio.h>
#include <math.h>
int main(){
	int n, arr[10][10];
	printf("How many numbers? : ");
	scanf("%d", &n);
	printf("Enter the binary numbers : \n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 0; i < n; i++){
		int sum = 0;
		for (int j = 0; j < 4; j++)
			sum += arr[i][j] * pow(2, 3 - j);
		if (sum < 10)
			printf("%d\n", sum);
		else
			printf("%c\n", sum + 55);
		}
	return 0;
}
