#include <stdio.h>

int Input(int* arr, int len) 
{
int i;
for(i=0;i<len;i++)
	scanf("%d",&arr[i]);
return i;
}

float Average(int *arr,int len)
{
int i;
float sum = 0;
    for (i = 0; i < len; i++)
        sum = sum + arr[i];
return sum/len;
}

int main(void)
{
	float avarege_num;
	int arr[12];
	Input(arr,12);
	avarege_num = Average(arr,12);
	printf("%.2f",avarege_num);
	return 0;
}


