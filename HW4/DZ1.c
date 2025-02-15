#include <stdio.h>

int main(void)
{
	int a,b,max,min;
	scanf("%d%d", &a, &b);
	max = a > b ? a : b;
	min = a > b ? b : a;
	printf("%d %d", min, max);
	return 0;
}

