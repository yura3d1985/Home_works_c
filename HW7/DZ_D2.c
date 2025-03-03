#include <stdio.h>

int func_sum(int n)
{
	static int i=1;
	static int sum=0;
	
	while (i<=n)
	{
		sum=sum+i;
		i++;
		func_sum(n-1);
	}
	return sum;
}

int main(void)
{
	int n,y;
	scanf("%d", &n);
    y=func_sum(n);
    printf("%d", y);
    return 0;
}

