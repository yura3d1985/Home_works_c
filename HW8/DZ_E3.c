#include <stdio.h>

int Input(int* arr, int len) 
{
int i;
for(i=0;i<len;i++)
	scanf("%d",&arr[i]);
return i;
}

int MIN_num(int *arr,int len)
{
int i, min;
min = arr[0];

    for (i = 1; i < len; i++)
    {
        if (min>arr[i])
			min = arr[i];
    }
return min;
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

int find_index(int *arr, int len, int num)
{
int i;
    for (i = 0; i < len; i++)
    {
        if (num == arr[i])
        return i+1;
    }
return 0;
}

int main(void)
{
	int min, min_index, max, max_index;
	int arr[10];
	Input(arr,10);
	min = MIN_num(arr,10);
	max = MAX_num(arr,10);
	min_index = find_index(arr,10,min);
	max_index = find_index(arr,10,max);
	printf("%d %d ",max_index,max);
	printf("%d %d",min_index,min);
	return 0;
}

