#include <stdio.h>

void chess_func(char s[2])
{
	int tmp, tmp_1, tmp_2;
	tmp_1 = (s[0] - 'A') + 1;
	tmp_2 = (s[1] - '1') + 1;
	tmp = tmp_1 + tmp_2;
	if ((tmp%2)!=0)
	printf("WHITE");
	else
	printf("BLACK");
}


int main(void)
{
	
	char s[2];
	scanf("%s",s);
	chess_func(s);
	return 0;
}

