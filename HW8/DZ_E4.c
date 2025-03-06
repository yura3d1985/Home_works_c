#include <stdio.h>

int Input(int* arr, int len) 
{
int i;
for(i=0;i<len;i++)
	scanf("%d",&arr[i]);
return i;
}

int MAX_sum(int *arr,int len)
{
int i, max1, max2;
int arr_tmp[len-1];

max1 = arr[0];

    for (i = 0; i < len; i++)
    {
        if (max1<arr[i])
        {
			arr_tmp[i-1] = max1;
			max1 = arr[i];
		}
		else
			arr_tmp[i-1] = arr[i];
    }
    
max2 = arr_tmp[0];

	for (i = 0; i < len-1; i++)
    {
        if (max2<arr_tmp[i])
			max2 = arr[i];
    }
	
return max1+max2;
}

int main(void)
{
	int num;
	int arr[10];
	Input(arr,10);
	num = MAX_sum(arr,10);
	printf("%d",num);
	return 0;
}

