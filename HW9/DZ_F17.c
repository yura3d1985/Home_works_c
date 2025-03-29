#include <stdio.h>

void scan_matrix (int m, int n, int a[m][n])
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
}

void print_matrix (int m, int n, int a[m][n])
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf ("%d ", a[i][j]);
		}
		printf ("\n");
	}
}


int main(void) 
{
	int i;
	int sum=0, array_size=5;
	int square_array[array_size][array_size];
	scan_matrix(array_size,array_size,square_array);
	for (i = 0; i < array_size; i++)
	{
		sum = sum + square_array[i][i];
	} 
	printf ("%d", sum);
	return 0;
}
