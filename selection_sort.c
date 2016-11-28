// Worst-case performance 	О(n2)
// Best-case performance 	О(n2)
// Average performance 	О(n2)

#include<stdio.h>

int main()
{
	int a[50], n, number, i, j, flag=0, count = 0, temp, position;

	printf("\nEnter the number of elements: ");
	scanf("%d",&n);

	printf("\nEnter the numbers\n");
	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}

	for(i = 0; i < n; i++)
	{
		position = i;

		for(j = i + 1; j <n ; j++)
		{
			if(a[position] > a[j])
				position = j;
		}

		if(position != i)
		{
			temp = a[i];
			a[i] = a[position];
			a[position] = temp;
		}

	}

	printf("\nSorted Array\n");
	for(i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
}