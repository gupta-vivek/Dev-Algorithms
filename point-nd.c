#include<stdio.h>
#include<math.h>

struct points {
	double coordinate[30];
	double distance;
} point[30], desired;

int main() {

	double x[30], temp;
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
	for(i=0; i<n; i++) {
		printf("%d. (", i+1);
		
		for(j=0; j<dimension-1; j++) {
			printf("%lf, ", point[i].coordinate[j]);
		}

		printf("%lf)\n", point[i].coordinate[j]);
	}

	printf("\nEnter the index of desired point: \n");
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
	for(i=0; i<n; i++) {
		printf("%d. (", i+1);
		
		for(j=0; j<dimension-1; j++) {
			printf("%lf, ", point[i].coordinate[j]);
		}

		printf("%lf) - %lf\n", point[i].coordinate[j], point[i].distance);
	}

	//Sorting.
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
			for(j=0; j<dimension; j++) {
				temp = point[i].coordinate[j];
				point[i].coordinate[j] = point[position].coordinate[j];
				point[position].coordinate[j] = temp;
			}

			temp = point[i].distance;
			point[i].distance = point[position].distance;
			point[position].distance = temp;
		}

	}

	printf("\n\nThese are the distances after sorting\n");
	for(i=0; i<n; i++) {
		printf("%d. (", i+1);
		
		for(j=0; j<dimension-1; j++) {
			printf("%lf, ", point[i].coordinate[j]);
		}

		printf("%lf) - %lf\n", point[i].coordinate[j], point[i].distance);
	}

	printf("\nNearby Points\n");
	for(i=1; i<=nearby; i++) {
		printf("%d. (", i);
		
		for(j=0; j<dimension-1; j++) {
			printf("%lf, ", point[i].coordinate[j]);
		}

		printf("%lf) - %lf\n", point[i].coordinate[j], point[i].distance);
	}

	printf("\n");

	return 0;
}