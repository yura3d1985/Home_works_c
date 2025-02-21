#include <stdio.h>

int main(void)
{
	int i, a, b;
	scanf("%d%d", &a, &b);
	if (a<=b)
		for (i=a; i<=b; i++)
		{
		printf("%d ", i*i);
		}
	else
		printf("No result");
	return 0;
}

