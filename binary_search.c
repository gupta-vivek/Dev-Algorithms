// Worst-case performance 	O(log n)
// Best-case performance 	O(1)
// Average performance 	O(log n)


#include<stdio.h>

int main() {
	int a[50], n, number, i, flag=0;
	int first = 0, last, middle;

	printf("\nEnter the number of elements: ");
	scanf("%d",&n);

	printf("\nEnter the numbers in ascending order\n");
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}

	printf("\nEnter the number to be searched: ");
	scanf("%d", &number);

	first = 0;
	last = n-1;
	middle = (first + last)/2;

	while(first<=last) {

		if(a[middle] < number )
			first = middle + 1;

		else if(a[middle] == number) {
			flag = 1;
			break;
		}

		else
			last = middle - 1;

		middle = (first + last)/2;
	}

	if(flag == 1)
		printf("\nNumber found at location - %d\n", middle)+1;
	else
		printf("\nNumber not found!\n");

}