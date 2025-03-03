#include <stdio.h>

void print_num(int num)
{	
	if ((num/10)!=0)
	{
		printf("%d ", num%10);
		print_num(num/10);
	}
	else
		printf("%d ", num);
}

int main(void)
{
	int num;
	scanf("%d", &num);
    print_num(num);
    return 0;
}

