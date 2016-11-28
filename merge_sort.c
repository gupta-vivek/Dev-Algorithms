// Worst-case performance 	O(n log n)
// Best-case performance 	O(n log n) typical, O(n) natural variant
// Average performance 	O(n log n)

#include<stdio.h>

void MergeSort(int *a, int l, int r);
void Merge(int *a, int i1, int j1, int i2, int j2);

int main() {

	int i, n, array[50];

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("\nEnter the numbers:\n");
	for(i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	MergeSort(array, 0, n-1);

	printf("\nSorted Array\n");
	for(i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	
	return 0;

}


void MergeSort(int *a, int low, int high) {

	int mid;

	if(low < high) {
		
		mid = (low + high)/2;
		MergeSort(a, low, mid); // Left array.
		MergeSort(a, mid + 1, high); // Right array.
		Merge(a, low, mid, mid + 1, high);
	}
}

void Merge(int *a, int i1, int j1, int i2, int j2) {

	int temp[50]; // Temporary array used for merging.

	int i = i1; // Beginning of the left array.
	int j = i2; // Beginning of the right array.
	int k = 0;

	while (i<=j1 && j<=j2) {
		
		if(a[i] < a[j]) {
			temp[k] = a[i];
			k++;
			i++;
		}

		else {
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Copying remaining elements from the left array.
	while( i <= j1) {
		temp[k] = a[i];
		i++;
		k++;
	}

	// Copying remaining elements from the right array.
	while( j <= j2) {
		temp[k] = a[j];
		j++;
		k++;
	}

	// Copying elements from temporary array to main array.
	for(i = i1, j = 0; i <= j2; i++, j++) {
		a[i] = temp[j];
	}
}