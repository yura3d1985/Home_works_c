#include <stdio.h>
#include <math.h>

int sum_n(int n)
{
	int i,a=0;
	for (i=1; i<=n; i++)
	{
		a = a + i; 
	}
	return a;
}
int main(void)
{
	int n,result;
	scanf("%d", &n);
	result = sum_n(n);
	printf("%d\n", result);
	return 0;
}

