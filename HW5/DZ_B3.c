#include <stdio.h>

int main(void)
{
	int i, a, b, c=0;
	scanf("%d%d", &a, &b);
	if (a<=b)
	{
		for (i=a; i<=b; i++)
		{
			c = c + i*i;
		}
		printf("%d\n", c);
	}
	else
		printf("No result");
	return 0;
}
