#include <stdio.h>

int print_n(int n)
{
	static int i=1;
	
	while (i<=n)
	{
		printf("%d ", i);
		i++;
		print_n(n-1);
	}
	return 0;
}

int main(void)
{
	int n;
	scanf("%d", &n);
    print_n(n);
    return 0;
}

