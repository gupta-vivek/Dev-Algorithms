#include<stdio.h>
#include<math.h>

// distance = 1, if you want to print the distance else 0.
void printItems(int low, int high, int dimension, int distance);

struct points {
	double coordinate[30];
	double distance;
} point[30], temp, desired;

int main() {

	double x[30];
	int i, n, nearby, dimension, j, index, position;

	printf("\nEnter the number of dimensions: ");
	scanf("%d", &dimension);

	printf("\nEnter the number of points: ");
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		printf("\nPoint - %d\n", i+1);

		for(j=0; j<dimension; j++) {
			printf("Enter co-ordinate-%d: ", j+1);
			scanf("%lf", &point[i].coordinate[j]);
		}
	}

	printf("\n\nThese are the entered co-ordinates\n");
	printItems(0, n, dimension, 0);

	printf("\nEnter the index of desired point: ");
	scanf("%d", &index);
	printf("\nRequired number of nearby points: ");
	scanf("%d", &nearby);

	index--;
	for(j=0; j<dimension; j++) {
		desired.coordinate[j] = point[index].coordinate[j];
	}

	printf("\n\nThis is the desired co-ordinate\n");
	printf("(");
		
	for(j=0; j<dimension-1; j++) {
		printf("%lf, ", desired.coordinate[j]);
	}

	printf("%lf)\n", desired.coordinate[j]);


	//Calculate the distance.
	for(i=0; i<n; i++) {

		point[i].distance = 0;

		for(j=0; j<dimension; j++) {
			x[j] = pow(point[i].coordinate[j] - desired.coordinate[j], 2);
		}

		for(j=0; j<dimension; j++) {
			point[i].distance = point[i].distance + x[j];
		}

		point[i].distance = sqrt(point[i].distance);
	}

	printf("\n\nThese are the distances\n");
	printItems(0, n, dimension, 1);

	//Sort.
	for(i = 0; i < n; i++)
	{
		position = i;

		for(j = i + 1; j <n ; j++)
		{
			if(point[position].distance > point[j].distance)
				position = j;
		}

		if(position != i)
		{
			temp = point[i];
			point[i] = point[position];
			point[position] = temp;
		}

	}

	printf("\n\nThese are the distances after sorting\n");
	printItems(0, n, dimension, 1);
	printf("\nNearby Points\n");
	printItems(1, nearby + 1, dimension, 1);
	printf("\n");

	return 0;
}

void printItems(int low, int high, int dimension, int distance) {
	int i, j;

	if(distance == 0) {

		for(i=low; i<high; i++) {
		printf("%d. (", i+1);
		
		for(j=0; j<dimension-1; j++) {
			printf("%lf, ", point[i].coordinate[j]);
		}

		printf("%lf)\n", point[i].coordinate[j]);
		}

	}

	else {

		for(i=low; i<high; i++) {
			printf("%d. (", i+1);
		
			for(j=0; j<dimension-1; j++) {
				printf("%lf, ", point[i].coordinate[j]);
			}

			printf("%lf) - %lf\n", point[i].coordinate[j], point[i].distance);
		}
	}
}
