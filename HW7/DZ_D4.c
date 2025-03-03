#include <stdio.h>

void print_num(int num)
{	
	int i=10;
	while ((num/i)!=0)
	{
		i=i*10;
	}
	if ((num/10)!=0)
	{
		printf("%d ", num/(i/10));
		print_num(num%(i/10));
	}
	else
	{	
		printf("%d ", num);
	}	
}

int main(void)
{
	int num;
	scanf("%d", &num);
    print_num(num);
    return 0;
}

