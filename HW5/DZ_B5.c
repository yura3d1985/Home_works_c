#include <stdio.h>

int main(void)
{
	int a, b=0;
	scanf("%d", &a);
	while (a!=0)
	{
        b += a % 10;
        a = a / 10;
	}
	printf("%d\n", b);
	return 0;
}

