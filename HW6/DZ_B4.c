#include <stdio.h>

int main(void)
{
	int a,i=0;
	scanf("%d", &a);
	while (a!=0)
	{
		a = a/10;
		i++;
	}
	if (i==3)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

