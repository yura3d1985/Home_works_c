#include <stdio.h>
#include <math.h>

int middle(int a, int b)
{
	return (a+b)/2;
}
int main(void)
{
	int a,b,c;
	scanf("%d%d", &a, &b);
	c = middle(a,b);
	printf("%d\n", c);
	return 0;
}

