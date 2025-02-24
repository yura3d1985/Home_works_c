#include <stdio.h>

int abs(int a)
{
	if (a<0)
		return a = -a;
	else
		return a;
}
int main(void)
{
	int a;
	scanf("%d", &a);
	a = abs(a);
	printf("%d\n", a);
	return 0;
}

