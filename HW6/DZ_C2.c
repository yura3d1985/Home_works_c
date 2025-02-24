#include <stdio.h>
#include <math.h>

int square(int a, int b)
{
	return pow(a,b);
}
int main(void)
{
	int a,b,c;
	scanf("%d%d", &a, &b);
	c = square(a,b);
	printf("%d\n", c);
	return 0;
}

