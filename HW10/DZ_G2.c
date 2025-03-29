#include <stdio.h>

int main(void)
{
	FILE *f; 
	int i, number;
	signed char c[100];
	
	f = fopen("input.txt", "r");
	
	fscanf(f, "%d", &number);

	fclose (f);
	
	c[0] = 65;
	c[1] = 50;
		
	for (i=2; i<number; i++)
	{
		if ((i%2) == 0)
		c[i] = c[i-2] + 1;
		else
		{
			if (c[i-2]>=56)
			c[i] = 50;	
			else
			c[i] = c[i-2] + 2;	
		}
	}
		
	f = fopen("output.txt", "w");
	
	fprintf(f, "%s", c);
	fclose (f);
		
	return 0;
}

