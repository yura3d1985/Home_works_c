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

float average_diagonal_num(int m, int n, int a[m][n])
{
	int sum=0;
	int i;
	for (i = 0; i <m; i++)
	{
		sum = sum + a[i][i];
	} 
	return sum/m;
}

int main(void) 
{
	int i,j,n=0,array_size=5;
	float average;
	int square_array[array_size][array_size];
	scan_matrix(array_size,array_size,square_array);
	average = average_diagonal_num(5, 5, square_array);
	for (i = 0; i < array_size; i++)
	{
		for (j = 0; j < array_size; j++)
		{
			if (square_array[i][j]>average)
			n=n+1;	
		}
	}
	printf ("%d", n);
	return 0;
}
