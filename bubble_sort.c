// Worst-case performance 	O ( n 2 )
// Best-case performance 	O ( n )
// Average performance 	O ( n 2 )


#include<stdio.h>

int main() {

	int a[50], n, number, i, j, flag=0, count = 0, temp, position;

	printf("\nEnter the number of elements: ");
	scanf("%d",&n);

	printf("\nEnter the numbers\n");
	for(i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}

	for(i = 0; i < (n-1); i++) {

		flag = 0;
		
		for(j = 0; j < (n-i-1); j++) {

			if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				
				flag = 1; // To check if the array is already sorted.
			}
		}

		if(flag == 0)
			break;

	}

	printf("\nSorted Array\n");
	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;
}