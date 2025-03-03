#include <stdio.h>

void print_num(int n)
{
	printf("%d ", n);
	if (n != 1)
		print_num(n - 1);
}

int main(void)
{
	int n;
	scanf("%d", &n);
    print_num(n);
    return 0;
}

