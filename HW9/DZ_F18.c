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

int MAX_num(int *arr,int len)
{
int i, max;
max = arr[0];

    for (i = 1; i < len; i++)
    {
        if (max<arr[i])
			max = arr[i];
    }
return max;
}

int main(void) 
{
	int array_tmp[10];
	int square_array[10][10];
	/*int square_array[10][10] =	{
									{61, 75, 55, 2, 35, 34, 77, 93, 28, 49},
									{11, 34, 22, 78, 19, 14, 67, 67, 11, 0},
									{72, 39, 23, 53, 92, 51, 60, 34, 71, 63},
									{14, 27, 72, 6, 0, 79, 98, 56, 30, 15},
									{31, 16, 3, 4, 95, 59, 25, 17, 11, 20},
									{5, 93, 21, 61, 96, 30, 79, 38, 73, 40},
									{89, 4, 66, 19, 36, 99, 67, 67, 92, 36},
									{87, 54, 7, 35, 40, 43, 44, 46, 4, 69},
									{98, 57, 20, 75, 9, 66, 85, 9, 39, 31},
									{8, 90, 94, 25, 12, 30, 18, 10, 23, 15}
								};*/
	int i, j, sum=0, max_number;
	
	scan_matrix (10, 10, square_array);
	
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			array_tmp[j]=square_array[i][j];
		}
		max_number = MAX_num(array_tmp,10);
		sum = sum + max_number;
	} 
	printf ("%d", sum);
	return 0;
}
