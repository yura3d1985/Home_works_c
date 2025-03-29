#include <stdio.h>

int main(void)
{
	int i, j, n = 0, m = 0, n_1 = 0, n_2 = 0, rep_count;
	FILE *f; 
	signed char c_tmp, word_1[100], word_1_tmp[100], word_2[100], word_2_tmp[100];
	
	f = fopen("input.txt", "r");
		
	while ((((c_tmp = fgetc(f)) != EOF ) && (c_tmp != '\n')) && (c_tmp != ' '))
	{    
		word_1[n_1] = c_tmp;
		n_1 = n_1 + 1; 
	} 
	word_1[n_1] = '\0';
	
	rep_count = 0;
	
	for (i=0; i<n_1; i++)
	{
		for (j=0; j<n_1; j++)
		{
			if ((i != j) && (word_1[i] == word_1[j]))
			rep_count = rep_count + 1;
		}
		if (rep_count == 0)
		{
			word_1_tmp[n] = word_1[i];
			n = n + 1; 
		}
		else
			rep_count = 0;
	}
		
	while ((((c_tmp = fgetc(f)) != EOF ) && (c_tmp != '\n')) && (c_tmp != ' '))
	{    
		word_2[n_2] = c_tmp;
		n_2 = n_2 + 1; 
	} 
	word_2[n_2] = '\0';
	
	rep_count = 0;
	
	for (i=0; i<n_2; i++)
	{
		for (j=0; j<n_2; j++)
		{
			if ((i != j) && (word_2[i] == word_2[j]))
			rep_count = rep_count + 1;
		}
		if (rep_count == 0)
		{
			word_2_tmp[m] = word_2[i];
			m = m + 1; 
		}
		else
			rep_count = 0;
	}
	
	fclose (f);
	
	f = fopen("output.txt", "w");
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			if (word_1_tmp[i] == word_2_tmp[j])
			fprintf(f, "%c ", word_1_tmp[i]);
		}
	}
	
	fclose (f);
	return 0;
}

