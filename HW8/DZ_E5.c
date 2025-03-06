#include <stdio.h>

int Input(int* arr, int len) 
{
int i;
for(i=0;i<len;i++)
	scanf("%d",&arr[i]);
return i;
}

int POS_sum(int *arr,int len)
{
int i, pos_sum=0;

    for (i = 0; i < len; i++)
    {
        if (arr[i]>0)
			pos_sum = pos_sum+arr[i];
    }

return pos_sum;
}

int main(void)
{
	int num;
	int arr[10];
	Input(arr,10);
	num = POS_sum(arr,10);
	printf("%d",num);
	return 0;
}

