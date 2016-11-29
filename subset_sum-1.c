#include<stdio.h>


void MergeSort(float *a, int l, int r);
void Merge(float *a, int i1, int j1, int i2, int j2);
void SubsetSum(float *a, int n, float sum);


int main() {

	int i, n;
	float array[50], sum;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("\nEnter the numbers:\n");
	for(i = 0; i < n; i++) {
		scanf("%f", &array[i]);
	}

	printf("\nEnter the sum: ");
	scanf("%f", &sum);

	MergeSort(array, 0, n-1);
	SubsetSum(array, n-1, sum);
	
	return 0;
}


void MergeSort(float *a, int low, int high) {

	int mid;

	if(low < high) {
		mid = (low + high)/2;
		MergeSort(a, low, mid); // Left array.
		MergeSort(a, mid + 1, high); // Right array.
		Merge(a, low, mid, mid + 1, high);
	}
}


void Merge(float *a, int i1, int j1, int i2, int j2) {

	float temp[50]; // Temporary array used for merging.
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