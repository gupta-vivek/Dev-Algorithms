// Worst-case performance 	O(n)
// Best-case performance 	O(1)
// Average performance 	O(n)

#include<stdio.h>

int main() {
	int a[50], n, number, i, count = 0;

	printf("\nEnter the number of elements: ");
	scanf("%d",&n);

	printf("\nEnter the numbers\n");
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}

	printf("\nEnter the number to be searched: " );
	scanf("%d",&number);

	for(i=0; i<n; i++) {
		if(number==a[i]) {
			printf("\nThe number is found at location - %d", i+1);
			count++;
		}
	}

	if(count>0)
		printf("\nNumber is present %d times in array.\n", count);
	else
		printf("\nNumber not found!\n");

	return 0;

}