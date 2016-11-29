#include<stdio.h>


void SubsetSum(float *a, int n, float sum);

int main() {

	int i, n;
	float array[50], sum;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("\nEnter the numbers in ascending order:\n");
	for(i = 0; i < n; i++) {
		scanf("%f", &array[i]);
	}

	printf("\nEnter the sum: ");
	scanf("%f", &sum);

	SubsetSum(array, n-1, sum);
	
	return 0;
}


void SubsetSum(float *a, int n, float sum) {

	int i = 0;
	int j = n;

	while(i<=j) {
	
		if(a[i] + a[j] == sum) {
			printf("\nPair Found: (%f, %f)", a[i], a[j]);
			i++;
			j--;
		}

		else if(sum > (a[i] + a[j]))
			i++;

		else if(sum < (a[i] + a[j]))
			j--;
	}
}