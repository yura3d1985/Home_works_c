#include <stdio.h>

int main(void)
{
	int i, n = 0;
	FILE *f; 
	signed char c_tmp, c[1000];
	
	f = fopen("input.txt", "r");
	
	while (((c_tmp = fgetc(f)) != EOF ) && (c_tmp != '\n'))
	{    
		c[n] = c_tmp;
		n = n + 1; 
	} 
	c[n] = '\0';
	fclose (f);
	
	f = fopen("output.txt", "w");
	
	for (i=0; i<(n-1); i++)
	{
		if (c[i]==c[n-1])
			fprintf (f, "%d ", i);
	}
	
	fclose (f);
	return 0;
}

