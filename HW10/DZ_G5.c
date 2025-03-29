#include <stdio.h>

int main(void)
{
	int i, n = 0;
	FILE *f; 
	signed char c_tmp, word[1000];
	
	f = fopen("input.txt", "r");
		
	while (((c_tmp = fgetc(f)) != EOF ) && (c_tmp != '\n'))
	{    
		word[n] = c_tmp;
		n++; 
	} 
	word[n] = '\0';
	
	for (i=0; i<n; i++)
	{
		c_tmp = word[i];
		
		if (c_tmp=='a') word[i] = 'b';
		if (c_tmp=='A') word[i] = 'B';
		if (c_tmp=='b') word[i] = 'a';
		if (c_tmp=='B') word[i] = 'A';
	}
	
	fclose (f);
	
	f = fopen("output.txt", "w");
	
	fprintf(f, "%s", word);
	
	fclose (f);

	return 0;
}
