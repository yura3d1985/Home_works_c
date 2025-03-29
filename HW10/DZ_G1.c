#include <stdio.h>

int main(void)
{
	int i, n = 0;
	FILE *f; 
	signed char c_tmp, c[100];
	
	f = fopen("input.txt", "r");
	
	while (((c_tmp = fgetc(f)) != EOF ) && (c_tmp != '\n'))
	{    
		c[n] = c_tmp;
		n = n + 1; 
	} 
	c[n] = '\0';
	fclose (f);
	
	f = fopen("output.txt", "w");
	
	for (i=0; i<3; i++)
	{
		fprintf(f, "%s", c);
		if (i!=2)
			fprintf (f, ", ");
	}
	fprintf (f, " %d", n);
	fclose (f);
	return 0;
}

