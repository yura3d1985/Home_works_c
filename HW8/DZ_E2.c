
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

int main(void)
{
	int min;
	int arr[5];
	Input(arr,5);
	min = MIN_num(arr,5);
	printf("%d",min);
	return 0;
}

