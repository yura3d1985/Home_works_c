#include <stdio.h>
#include <math.h>


int Input(int* arr, int len) 
{
int i;
for(i=0;i<len;i++)
	scanf("%d",&arr[i]);
return i;
}

int count_bigger_abs(int n, int a[n])
{
int i, count=0, max;
max = a[0];

    for (i = 1; i < n; i++)
    {
        if (max<a[i])
			max = a[i];
    }
    for(i=0;i<n;i++)
	{
		if (abs(a[i])>max)
			count = count + 1;
	}
return count;
}

int main(void)
{
	int n=0;
	int arr[10];
	Input(arr,10);
	n = count_bigger_abs(10,arr);
	printf("%d",n);
	return 0;
}

