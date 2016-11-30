#include<stdio.h>
#include<math.h>

int main() {

	double a[20][3], x, y, x1, y1, temp;
	int i, n, nearby, index, position, j;

	printf("\nEnter the number of points: ");
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		printf("\nPoint - %d", i+1);
		printf("\nEnter the x co-ordinate: ");
		scanf("%lf", &a[i][0]);
		printf("Enter the y co-ordinate: ");
		scanf("%lf", &a[i][1]);
	}

	printf("\n\nThese are the entered co-ordinates");
	for(i=0; i<n; i++) {
		printf("\n%d. (%lf, %lf)",i+1, a[i][0], a[i][1]);
	}

	printf("\n\nEnter the index of desired point: ");
	scanf("%d", &index);
	index--;
	x1 = a[index][0];
	y1 = a[index][1];
	printf("\nRequired number of nearby points: ");
	scanf("%d", &nearby);

	//Calculate the distance of points.
	for(i=0; i<n; i++) {	
		x = pow(a[i][0] - x1, 2);
		y = pow(a[i][1] - y1, 2);
		a[i][2] = sqrt(x + y);

		if(a[i][2] < a[i-1][2]) {
			temp = a[i][0];
			a[i][0] = a[i-1][0];
			a[i-1][0] = temp;

			temp = a[i][1];
			a[i][1] = a[i-1][1];
			a[i-1][1] = temp;

			temp = a[i][2];
			a[i][2] = a[i-1][2];
			a[i-1][2] = temp;
		}

	}

	//Sorting by distance.
	for(i = 0; i < n; i++)
	{
		position = i;

		for(j = i + 1; j <n ; j++)
		{
			if(a[position][2] > a[j][2])
				position = j;
		}

		if(position != i)
		{
			temp = a[i][0];
			a[i][0] = a[position][0];
			a[position][0] = temp;

			temp = a[i][1];
			a[i][1] = a[position][1];
			a[position][1] = temp;

			temp = a[i][2];
			a[i][2] = a[position][2];
			a[position][2] = temp;
		}

	}


	for(i=0; i<n; i++) {
		printf("\n(%lf, %lf) - %lf", a[i][0], a[i][1], a[i][2]);
	}

	printf("\nNearby Points");

	for(i=1; i<=nearby; i++) {
		printf("\n(%lf, %lf) - %lf", a[i][0], a[i][1], a[i][2]);
	}

	printf("\n");

	return 0;
}